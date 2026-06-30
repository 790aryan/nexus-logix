#include "core/AlgorithmRegistry.hpp"

#include <iostream>

void AlgorithmRegistry::registerAlgorithm(
    std::shared_ptr<Algorithm> algorithm
)
{
    algorithms[algorithm->getName()] = algorithm;
}

std::shared_ptr<Algorithm>
AlgorithmRegistry::getAlgorithm(
    const std::string& name
)
{
    if (algorithms.count(name))
        return algorithms[name];

    return nullptr;
}

void AlgorithmRegistry::listAlgorithms() const
{
    std::cout << "\nRegistered Algorithms\n";
    std::cout << "---------------------\n";

    for (const auto& algorithm : algorithms)
    {
        std::cout << algorithm.first << '\n';
    }
}