#include "simulator/WarehouseGenerator.hpp"

#include <random>

namespace
{
    const std::vector<std::string> cities =
    {
        "Mumbai",
        "Delhi",
        "Bengaluru",
        "Hyderabad",
        "Chennai",
        "Kolkata",
        "Pune",
        "Ahmedabad"
    };

    const std::vector<std::string> states =
    {
        "Maharashtra",
        "Delhi",
        "Karnataka",
        "Telangana",
        "Tamil Nadu",
        "West Bengal",
        "Maharashtra",
        "Gujarat"
    };

    std::mt19937 rng(std::random_device{}());
}

Warehouse WarehouseGenerator::generateWarehouse(int id)
{
    std::uniform_int_distribution<> cityDist(0, cities.size() - 1);
    std::uniform_int_distribution<> capacityDist(5000, 50000);
    std::uniform_int_distribution<> inventoryDist(1000, 40000);
    std::uniform_real_distribution<> latDist(8.0, 37.0);
    std::uniform_real_distribution<> lonDist(68.0, 97.0);

    int cityIndex = cityDist(rng);

    Warehouse warehouse;

    warehouse.id = id;

    warehouse.code = "WH-" + std::to_string(100 + id);

    warehouse.name = cities[cityIndex] + " Distribution Center";

    warehouse.city = cities[cityIndex];

    warehouse.state = states[cityIndex];

    warehouse.latitude = latDist(rng);

    warehouse.longitude = lonDist(rng);

    warehouse.capacity = capacityDist(rng);

    warehouse.currentInventory = inventoryDist(rng);

    return warehouse;
}

std::vector<Warehouse>
WarehouseGenerator::generateWarehouses(
    int totalWarehouses
)
{
    std::vector<Warehouse> warehouses;

    warehouses.reserve(totalWarehouses);

    for (int i = 1; i <= totalWarehouses; i++)
    {
        warehouses.push_back(generateWarehouse(i));
    }

    return warehouses;
}