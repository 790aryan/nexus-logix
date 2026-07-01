#pragma once

#include <memory>

#include "engine/RoutingStrategy.hpp"
#include "graph/WarehouseGraph.hpp"

class DijkstraAlgorithm;

class DijkstraStrategy : public RoutingStrategy
{
public:

    explicit DijkstraStrategy(
        const WarehouseGraph& graph
    );

    AlgorithmResult findRoute(
        int sourceNode,
        int destinationNode
    ) override;

private:

    std::shared_ptr<DijkstraAlgorithm> dijkstra;
};