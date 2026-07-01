#pragma once

#include <memory>

#include "engine/RoutingStrategy.hpp"
#include "graph/WarehouseGraph.hpp"

class AStarAlgorithm;

class AStarStrategy : public RoutingStrategy
{
public:

    explicit AStarStrategy(
        const WarehouseGraph& graph
    );

    AlgorithmResult findRoute(
        int sourceNode,
        int destinationNode
    ) override;

private:

    std::shared_ptr<AStarAlgorithm> aStar;
};