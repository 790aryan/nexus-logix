#pragma once

#include "core/Algorithm.hpp"
#include "graph/WarehouseGraph.hpp"

class AStarAlgorithm : public Algorithm
{
public:

    std::string getName() const override;

    AlgorithmResult execute(
        const AlgorithmInput& input
    ) override;

    void setGraph(
        const WarehouseGraph& graph
    );

private:

    double heuristic(
        int currentNode,
        int destinationNode
    ) const;

    const WarehouseGraph* graph = nullptr;
};