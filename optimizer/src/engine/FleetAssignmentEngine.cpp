#include "engine/FleetAssignmentEngine.hpp"

int FleetAssignmentEngine::assignOrders(
    std::vector<Order>& orders,
    std::vector<Vehicle>& fleet
)
{
    int assigned = 0;

    size_t vehicleIndex = 0;

    for(auto& order : orders)
    {
        while(
            vehicleIndex < fleet.size() &&
            !fleet[vehicleIndex].available
        )
        {
            vehicleIndex++;
        }

        if(vehicleIndex >= fleet.size())
        {
            break;
        }

        fleet[vehicleIndex].available = false;

        assigned++;
    }

    return assigned;
}