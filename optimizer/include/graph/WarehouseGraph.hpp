#pragma once

#include <unordered_map>
#include <vector>

#include "graph/Road.hpp"

class WarehouseGraph
{
public:
    void addRoad(const Road& road);

    const std::vector<Road>& getNeighbors(int warehouseId) const;

    const std::unordered_map<int, std::vector<Road>>&
    getAdjacencyList() const;

private:
    std::unordered_map<int, std::vector<Road>> adjacencyList;
};