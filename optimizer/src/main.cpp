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
WarehouseGraph graph;

RoadGenerator roadGenerator;

auto roads =
    roadGenerator.generateRoads(
        warehouses
    );


for (const auto& road : roads)
{
    graph.addRoad(road);
}

std::cout
    << "\nRoad Network\n";
std::cout
    << "------------\n";

std::cout
    << "Total Roads: "
    << roads.size()
    << "\n";

DijkstraAlgorithm dijkstra;

dijkstra.setGraph(graph);

engine.getRegistry().registerAlgorithm(
    std::make_shared<DijkstraAlgorithm>(dijkstra)
);

engine.getRegistry().listAlgorithms();


auto algo =
engine.getRegistry().getAlgorithm(
    "Dijkstra"
);

if(algo)
{
    BenchmarkRunner benchmark;

    AlgorithmInput input;

    input.sourceNode =
        warehouses.front().id;

    input.destinationNode =
        warehouses.back().id;

    auto result =
        benchmark.run(
            *algo,
            input
        );

    std::cout
        << "\nRoute Optimization\n";
    std::cout
        << "------------------\n";

    std::cout
        << result.message
        << "\n";

    if(result.success)
    {
        std::cout
            << "Distance : "
            << result.shortestDistance
            << " km\n";

        std::cout
            << "Path : ";

        for(int node :
            result.shortestPath)
        {
            std::cout
                << node
                << " ";
        }

        std::cout << "\n";
        std::cout
            << "Execution Time : "
            << result.metrics.executionTimeMs
            << " ms\n";
    }
}
    engine.shutdown();

    return 0;
}