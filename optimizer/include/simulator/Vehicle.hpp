#pragma once

#include <string>

struct Vehicle
{
    int id = 0;

    std::string vehicleNumber;

    double capacityKg = 0.0;

    int currentWarehouseId = 0;

    bool available = true;

    double currentLoadKg = 0.0;

    int assignedOrders = 0;

    double remainingCapacityKg = 0.0;
    
};