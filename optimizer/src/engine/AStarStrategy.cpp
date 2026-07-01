#include "engine/AStarStrategy.hpp"

#include <memory>

#include "algorithms/graph/AStarAlgorithm.hpp"
#include "benchmark/BenchmarkRunner.hpp"
#include "models/AlgorithmInput.hpp"

AStarStrategy::AStarStrategy(
    const WarehouseGraph& graph
)
{
    aStar =
        std::make_shared<AStarAlgorithm>();

    aStar->setGraph(graph);
}

AlgorithmResult
AStarStrategy::findRoute(
    int sourceNode,
    int destinationNode
)
{
    AlgorithmInput input;

    input.sourceNode = sourceNode;
    input.destinationNode = destinationNode;

    BenchmarkRunner benchmark;

    return benchmark.run(
        *aStar,
        input
    );
}