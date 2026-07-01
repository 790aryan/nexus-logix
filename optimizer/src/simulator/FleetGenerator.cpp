#include "simulator/FleetGenerator.hpp"

#include <random>

std::vector<Vehicle>
FleetGenerator::generateFleet(
    int vehicleCount,
    const std::vector<Warehouse>& warehouses
)
{
    std::vector<Vehicle> fleet;

    if(warehouses.empty())
    {
        return fleet;
    }

    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_real_distribution<>
        capacityDist(
            500.0,
            5000.0
        );

    std::uniform_int_distribution<>
        warehouseDist(
            0,
            static_cast<int>(warehouses.size()) - 1
        );

    for(int i = 1; i <= vehicleCount; i++)
    {
        Vehicle vehicle;

        vehicle.id = i;

        vehicle.vehicleNumber =
            "TRUCK-" +
            std::to_string(1000 + i);

        vehicle.capacityKg =
            capacityDist(gen);

        vehicle.currentWarehouseId =
            warehouses[
                warehouseDist(gen)
            ].id;

        vehicle.available = true;

        vehicle.currentLoadKg = 0.0;

        fleet.push_back(vehicle);
    }

    return fleet;
}