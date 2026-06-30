#include "algorithms/graph/DijkstraAlgorithm.hpp"

std::string
DijkstraAlgorithm::getName() const
{
    return "Dijkstra";
}

void DijkstraAlgorithm::setGraph(
    const WarehouseGraph& graphRef
)
{
    graph = &graphRef;
}

AlgorithmResult
DijkstraAlgorithm::execute(
    const AlgorithmInput&
)
{
    AlgorithmResult result;

    result.algorithmName = getName();

    if(graph == nullptr)
    {
        result.success = false;
        result.message = "Graph not initialized.";

        return result;
    }

    result.success = true;

    result.message =
        "Dijkstra skeleton ready.";

    return result;
}