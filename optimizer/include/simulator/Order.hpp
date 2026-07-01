#pragma once

#include <string>

struct Order
{
    int id = 0;

    int sourceWarehouseId = 0;

    int destinationWarehouseId = 0;

    int productId = 0;

    int quantity = 0;

    double weight = 0.0;
    
    int assignedVehicleId = -1;

    bool assigned = false;
    std::string status;
};