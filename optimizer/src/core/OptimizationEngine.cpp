#include "core/OptimizationEngine.hpp"

#include <iostream>

void OptimizationEngine::initialize()
{
    std::cout << "Initializing Optimization Engine...\n";
}

void OptimizationEngine::shutdown()
{
    std::cout << "Shutting down Optimization Engine...\n";
}

AlgorithmRegistry&
OptimizationEngine::getRegistry()
{
    return registry;
}