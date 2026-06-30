#include "algorithms/graph/DijkstraAlgorithm.hpp"
#include <queue>
#include <unordered_map>
#include <limits>

#include "models/DijkstraState.hpp"

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
    const AlgorithmInput&input
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

    if(input.sourceNode == -1)
{
    result.success = false;
    result.message = "Invalid source node.";

    return result;
}

std::priority_queue<
    DijkstraState,
    std::vector<DijkstraState>,
    std::greater<DijkstraState>
> pq;

std::unordered_map<int,double> distance;
result.success = true;

result.message =
    "Priority queue initialized.";
    return result;
}