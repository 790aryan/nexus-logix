#include <iostream>
#include <memory>

#include "core/OptimizationEngine.hpp"
#include "algorithms/search/BinarySearchAlgorithm.hpp"
#include "benchmark/BenchmarkRunner.hpp"
#include "simulator/InventoryGenerator.hpp"

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
    engine.shutdown();

    return 0;
}