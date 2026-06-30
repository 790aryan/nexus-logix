#include "benchmark/BenchmarkRunner.hpp"

#include <chrono>

AlgorithmResult BenchmarkRunner::run(
    Algorithm& algorithm,
    const AlgorithmInput& input
)
{
    auto start =
        std::chrono::high_resolution_clock::now();

    AlgorithmResult result =
        algorithm.execute(input);

    auto end =
        std::chrono::high_resolution_clock::now();

    result.metrics.executionTimeMs =
        std::chrono::duration<double, std::milli>(
            end - start
        ).count();

    return result;
}