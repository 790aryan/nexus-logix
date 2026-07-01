#pragma once

#include "models/AlgorithmResult.hpp"

class RoutingStrategy
{
public:

    virtual ~RoutingStrategy() = default;

    virtual AlgorithmResult findRoute(
        int sourceNode,
        int destinationNode
    ) = 0;
};