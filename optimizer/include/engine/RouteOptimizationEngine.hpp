#pragma once

#include <memory>

#include "graph/WarehouseGraph.hpp"
#include "models/AlgorithmResult.hpp"

class DijkstraAlgorithm;

class RouteOptimizationEngine
{
public:

    explicit RouteOptimizationEngine(
        const WarehouseGraph& graph
    );

    AlgorithmResult findShortestRoute(
        int sourceNode,
        int destinationNode
    );

private:

    std::shared_ptr<DijkstraAlgorithm> dijkstra;
};