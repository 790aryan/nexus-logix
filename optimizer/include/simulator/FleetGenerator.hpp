#pragma once

#include <vector>

#include "simulator/Vehicle.hpp"
#include "simulator/Warehouse.hpp"

class FleetGenerator
{
public:

    std::vector<Vehicle> generateFleet(
        int vehicleCount,
        const std::vector<Warehouse>& warehouses
    );
};