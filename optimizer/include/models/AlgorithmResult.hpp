#pragma once

#include <string>
#include <vector>

#include "AlgorithmMetrics.hpp"

struct AlgorithmResult
{
    bool success = false;

    std::string algorithmName;

    std::string message;

    AlgorithmMetrics metrics;

    std::vector<int> output;
};