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

    double shortestDistance = 0.0;

    std::vector<int> shortestPath;
};