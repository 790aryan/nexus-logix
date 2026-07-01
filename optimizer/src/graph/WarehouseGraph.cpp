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
const std::unordered_map<int, std::vector<Road>>&
WarehouseGraph::getAdjacencyList() const
{
    return adjacencyList;
}
void WarehouseGraph::addWarehouse(
    const Warehouse& warehouse
)
{
    warehouses[warehouse.id] = warehouse;
}

const Warehouse*
WarehouseGraph::getWarehouse(
    int warehouseId
) const
{
    auto it = warehouses.find(warehouseId);

    if(it == warehouses.end())
    {
        return nullptr;
    }

    return &it->second;
}
