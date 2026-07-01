#pragma once

#include <vector>

#include "simulator/Order.hpp"
#include "simulator/Vehicle.hpp"

class FleetAssignmentEngine
{
public:

    int assignOrders(
        std::vector<Order>& orders,
        std::vector<Vehicle>& fleet
    );
};