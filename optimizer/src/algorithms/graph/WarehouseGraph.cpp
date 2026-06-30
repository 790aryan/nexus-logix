#include "graph/WarehouseGraph.hpp"

void WarehouseGraph::addRoad(
    const Road& road
)
{
    adjacencyList[
        road.sourceWarehouseId
    ].push_back(road);
}

const std::vector<Road>&
WarehouseGraph::getNeighbors(
    int warehouseId
) const
{
    static const std::vector<Road> empty;

    auto iterator =
        adjacencyList.find(warehouseId);

    if (iterator == adjacencyList.end())
    {
        return empty;
    }

    return iterator->second;
}