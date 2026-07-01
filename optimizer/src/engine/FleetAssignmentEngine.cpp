#include "engine/FleetAssignmentEngine.hpp"

int FleetAssignmentEngine::assignOrders(
    std::vector<Order>& orders,
    std::vector<Vehicle>& fleet
)
{
    int assigned = 0;

    for(auto& order : orders)
    {
        for(auto& vehicle : fleet)
        {
            if(!vehicle.available)
            {
                continue;
            }

            if(vehicle.remainingCapacityKg <
               order.weight)
            {
                continue;
            }

            vehicle.remainingCapacityKg -=
                order.weight;

            vehicle.assignedOrders++;

            vehicle.available = false;

            order.assigned = true;

            order.assignedVehicleId =
                vehicle.id;

            order.status = "Assigned";

            assigned++;

            break;
        }
    }

    return assigned;
}