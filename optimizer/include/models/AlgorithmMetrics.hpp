#pragma once

#include <cstddef>

struct AlgorithmMetrics
{
    double executionTimeMs = 0.0;

    std::size_t inputSize = 0;

    std::size_t outputSize = 0;
};