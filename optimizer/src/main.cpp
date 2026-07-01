#include <iostream>
#include <memory>

#include "core/OptimizationEngine.hpp"
#include "algorithms/search/BinarySearchAlgorithm.hpp"
#include "benchmark/BenchmarkRunner.hpp"
#include "simulator/InventoryGenerator.hpp"
#include "simulator/WarehouseGenerator.hpp"
#include "simulator/RoadGenerator.hpp"
#include "graph/WarehouseGraph.hpp"
#include "algorithms/graph/DijkstraAlgorithm.hpp"
#include "testing/GraphTestBuilder.hpp"
#include "algorithms/trees/SegmentTree.hpp"
#include "engine/InventoryAnalyticsEngine.hpp"
#include "engine/RouteOptimizationEngine.hpp"
#include "simulator/OrderGenerator.hpp"
#include "simulator/FleetGenerator.hpp"

int main()
{
    std::cout << "=====================================\n";
    std::cout << "       OptiFlow Optimization Engine\n";
    std::cout << "=====================================\n\n";

    OptimizationEngine engine;

    engine.initialize();

    auto binarySearch =
        std::make_shared<BinarySearchAlgorithm>();

    engine.getRegistry().registerAlgorithm(
        binarySearch
    );

    engine.getRegistry().listAlgorithms();

    AlgorithmInput input;

    input.numbers =
    {
        2,
        4,
        7,
        9,
        11,
        15,
        18,
        22
    };

    input.target = 15;

    auto algorithm =
        engine.getRegistry().getAlgorithm(
            "Binary Search"
        );

    if (algorithm)
    {
        BenchmarkRunner benchmark;

        AlgorithmResult result =
            benchmark.run(*algorithm, input);

        std::cout << "\nResult\n";
        std::cout << "------\n";

        std::cout
            << result.message
            << "\n";

        if (!result.output.empty())
        {
            std::cout
                << "Index: "
                << result.output[0]
                << "\n";
            std::cout
                << "Execution Time: "
                << result.metrics.executionTimeMs
                << " ms\n";
        }
    }
InventoryGenerator generator;

const int PRODUCT_COUNT = 100000;

auto inventory =
    generator.generateInventory(
        PRODUCT_COUNT
    );




WarehouseGenerator warehouseGenerator;

const int WAREHOUSE_COUNT = 50;

auto warehouses =
    warehouseGenerator.generateWarehouses(
        WAREHOUSE_COUNT
    );

OrderGenerator orderGenerator;

const int ORDER_COUNT = 10000;

auto orders =
    orderGenerator.generateOrders(
        ORDER_COUNT,
        warehouses,
        inventory
    );

FleetGenerator fleetGenerator;

const int VEHICLE_COUNT = 500;

auto fleet =
    fleetGenerator.generateFleet(
        VEHICLE_COUNT,
        warehouses
    );


std::cout
    << "\n=====================================\n";
std::cout
    << "      Simulation Summary\n";
std::cout
    << "=====================================\n\n";

std::cout
    << "Products    : "
    << inventory.size()
    << "\n";

std::cout
    << "Warehouses  : "
    << warehouses.size()
    << "\n";

std::cout
    << "Orders      : "
    << orders.size()
    << "\n";

std::cout
    << "Vehicles    : "
    << fleet.size()
    << "\n";
GraphTestBuilder builder;

WarehouseGraph graph =
    builder.buildTestGraph();
for(const auto& warehouse : warehouses)
{
    graph.addWarehouse(
        warehouse
    );
}
std::cout
    << "\nTest Graph Loaded\n";

std::cout
    << "\nRoad Network\n";
std::cout
    << "------------\n";

std::cout
    << "Total Roads: 8\n";

std::cout
    << "\nRoute Optimization\n";
std::cout
    << "------------------\n";

RouteOptimizationEngine
    routeEngine(graph);

AlgorithmResult route =
    routeEngine.findShortestRoute(
        1,
        4
    );

std::cout
    << route.message
    << "\n";

if(route.success)
{
    std::cout
        << "Distance : "
        << route.shortestDistance
        << " km\n";

    std::cout
        << "Path : ";

    for(int node :
        route.shortestPath)
    {
        std::cout
            << node
            << " ";
    }

    std::cout << "\n";

    std::cout
        << "Execution Time : "
        << route.metrics.executionTimeMs
        << " ms\n";
}



std::cout
    << "\n=====================================\n";
std::cout
    << "    Inventory Analytics Engine\n";
std::cout
    << "=====================================\n";

std::vector<int> inventoryQuantities;

for(const auto& product : inventory)
{
    inventoryQuantities.push_back(
        product.quantity
    );
}

InventoryAnalyticsEngine analytics(
    inventoryQuantities
);

std::cout
    << "\nTotal Inventory : "
    << analytics.getTotalInventory()
    << "\n";

std::cout
    << "Inventory Range [1,3] : "
    << analytics.getInventoryRange(1,3)
    << "\n";

std::cout
    << "Average Inventory : "
    << analytics.getAverageInventory()
    << "\n";

std::cout
    << "Maximum Inventory : "
    << analytics.getMaximumInventory()
    << "\n";

std::cout
    << "Minimum Inventory : "
    << analytics.getMinimumInventory()
    << "\n";

std::cout
    << "\nUpdating Inventory Index 2 -> 200\n";

analytics.updateInventory(
    2,
    200
);

std::cout
    << "Updated Range [1,3] : "
    << analytics.getInventoryRange(1,3)
    << "\n";
    engine.shutdown();

    return 0;
}