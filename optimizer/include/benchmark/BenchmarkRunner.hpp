#pragma once

#include "core/Algorithm.hpp"

class BenchmarkRunner
{
public:
    AlgorithmResult run(
        Algorithm& algorithm,
        const AlgorithmInput& input
    );
};