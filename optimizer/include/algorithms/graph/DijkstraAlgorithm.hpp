#pragma once

#include "core/Algorithm.hpp"
#include "graph/WarehouseGraph.hpp"

class DijkstraAlgorithm : public Algorithm
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

    const WarehouseGraph* graph = nullptr;
};