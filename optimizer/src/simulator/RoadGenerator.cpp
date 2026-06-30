#include "simulator/RoadGenerator.hpp"

#include <cmath>
#include <random>
#include <set>

std::vector<Road>
RoadGenerator::generateRoads(
    const std::vector<Warehouse>& warehouses
)
{
    std::vector<Road> roads;

    if (warehouses.size() < 2)
        return roads;

    auto createRoad =
        [&](int fromIndex, int toIndex)
    {
        double dx =
            warehouses[fromIndex].latitude -
            warehouses[toIndex].latitude;

        double dy =
            warehouses[fromIndex].longitude -
            warehouses[toIndex].longitude;

        double distance =
            std::sqrt(dx * dx + dy * dy) * 111.0;

        Road road;

        road.sourceWarehouseId =
            warehouses[fromIndex].id;

        road.destinationWarehouseId =
            warehouses[toIndex].id;

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
    };

    //---------------------------------------------------
    // Backbone chain
    //---------------------------------------------------

    std::set<std::pair<int,int>> used;

    for(size_t i = 0; i + 1 < warehouses.size(); ++i)
    {
        createRoad(i, i + 1);

        used.insert({(int)i, (int)i + 1});
        used.insert({(int)i + 1, (int)i});
    }

    //---------------------------------------------------
    // Random shortcut roads
    //---------------------------------------------------

    std::mt19937 rng(std::random_device{}());

    std::uniform_int_distribution<int>
        node(0, (int)warehouses.size() - 1);

    int extraRoads =
        std::max(
            2,
            (int)warehouses.size() / 2
        );

    while(extraRoads > 0)
    {
        int u = node(rng);
        int v = node(rng);

        if(u == v)
            continue;

        if(used.count({u,v}))
            continue;

        createRoad(u,v);

        used.insert({u,v});
        used.insert({v,u});

        extraRoads--;
    }

    return roads;
}