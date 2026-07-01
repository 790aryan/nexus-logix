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

auto inventory = generator.generateInventory(5);

std::cout << "\nGenerated Inventory\n";
std::cout << "-------------------\n";

for(const auto& product : inventory)
{
    std::cout
        << product.sku
        << " | "
        << product.name
        << " | "
        << product.category
        << " | Qty: "
        << product.quantity
        << '\n';
}


WarehouseGenerator warehouseGenerator;

auto warehouses =
    warehouseGenerator.generateWarehouses(5);

std::cout << "\nGenerated Warehouses\n";
std::cout << "--------------------\n";

for (const auto& warehouse : warehouses)
{
    std::cout
        << warehouse.code
        << " | "
        << warehouse.city
        << " | Capacity: "
        << warehouse.capacity
        << " | Inventory: "
        << warehouse.currentInventory
        << '\n';
}
GraphTestBuilder builder;

WarehouseGraph graph =
    builder.buildTestGraph();

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