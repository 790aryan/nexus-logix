#include "engine/RouteOptimizationEngine.hpp"

#include "engine/DijkstraStrategy.hpp"

RouteOptimizationEngine::RouteOptimizationEngine(
    const WarehouseGraph& graph
)
{
    strategy =
        std::make_unique<DijkstraStrategy>(
            graph
        );
}

void RouteOptimizationEngine::setStrategy(
    std::unique_ptr<RoutingStrategy> newStrategy
)
{
    strategy = std::move(newStrategy);
}

AlgorithmResult
RouteOptimizationEngine::findShortestRoute(
    int sourceNode,
    int destinationNode
)
{
    return strategy->findRoute(
        sourceNode,
        destinationNode
    );
}