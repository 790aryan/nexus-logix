#include "engine/RouteOptimizationEngine.hpp"

#include <memory>

#include "algorithms/graph/DijkstraAlgorithm.hpp"
#include "benchmark/BenchmarkRunner.hpp"
#include "models/AlgorithmInput.hpp"

RouteOptimizationEngine::RouteOptimizationEngine(
    const WarehouseGraph& graph
)
{
    dijkstra =
        std::make_shared<DijkstraAlgorithm>();

    dijkstra->setGraph(graph);
}

AlgorithmResult
RouteOptimizationEngine::findShortestRoute(
    int sourceNode,
    int destinationNode
)
{
    AlgorithmInput input;

    input.sourceNode = sourceNode;
    input.destinationNode = destinationNode;

    BenchmarkRunner benchmark;

    return benchmark.run(
        *dijkstra,
        input
    );
}