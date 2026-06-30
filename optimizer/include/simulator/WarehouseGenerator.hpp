#pragma once

#include <vector>

#include "simulator/Warehouse.hpp"

class WarehouseGenerator
{
public:

    std::vector<Warehouse> generateWarehouses(
        int totalWarehouses
    );

private:

    Warehouse generateWarehouse(
        int id
    );
};