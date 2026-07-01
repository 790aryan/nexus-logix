#pragma once

#include <memory>

#include "engine/RoutingStrategy.hpp"
#include "graph/WarehouseGraph.hpp"
#include "models/AlgorithmResult.hpp"

class RouteOptimizationEngine
{
public:

    explicit RouteOptimizationEngine(
        const WarehouseGraph& graph
    );

    void setStrategy(
        std::unique_ptr<RoutingStrategy> strategy
    );

    AlgorithmResult findShortestRoute(
        int sourceNode,
        int destinationNode
    );

private:

    std::unique_ptr<RoutingStrategy> strategy;
};