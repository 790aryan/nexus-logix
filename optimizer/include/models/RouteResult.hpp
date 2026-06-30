#pragma once

#include <vector>

struct RouteResult
{
    double totalDistance = 0.0;

    std::vector<int> path;

    int visitedNodes = 0;
};