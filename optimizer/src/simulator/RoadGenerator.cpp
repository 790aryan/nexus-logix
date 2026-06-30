#include "simulator/RoadGenerator.hpp"

#include <cmath>

std::vector<Road>
RoadGenerator::generateRoads(
    const std::vector<Warehouse>& warehouses
)
{
    std::vector<Road> roads;

    for (size_t i = 0; i < warehouses.size(); ++i)
    {
        for (size_t j = i + 1; j < warehouses.size(); ++j)
        {
            double dx =
                warehouses[i].latitude -
                warehouses[j].latitude;

            double dy =
                warehouses[i].longitude -
                warehouses[j].longitude;

            double distance =
                std::sqrt(dx * dx + dy * dy) * 111.0;

            Road road;

            road.sourceWarehouseId =
                warehouses[i].id;

            road.destinationWarehouseId =
                warehouses[j].id;

            road.distanceKm = distance;

            road.travelTimeMinutes =
                distance;

            road.trafficFactor = 1.0;

            roads.push_back(road);

            Road reverse = road;

            reverse.sourceWarehouseId =
                road.destinationWarehouseId;

            reverse.destinationWarehouseId =
                road.sourceWarehouseId;

            roads.push_back(reverse);
        }
    }

    return roads;
}