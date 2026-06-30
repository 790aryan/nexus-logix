#pragma once

#include "AlgorithmRegistry.hpp"

class OptimizationEngine
{
private:
    AlgorithmRegistry registry;

public:
    void initialize();

    void shutdown();

    AlgorithmRegistry& getRegistry();
};