#pragma once

#include <vector>

#include "graph/Road.hpp"
#include "simulator/Warehouse.hpp"

class RoadGenerator
{
public:

    std::vector<Road> generateRoads(
        const std::vector<Warehouse>& warehouses
    );
};