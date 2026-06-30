#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "Algorithm.hpp"

class AlgorithmRegistry
{
private:
    std::unordered_map<
        std::string,
        std::shared_ptr<Algorithm>
    > algorithms;

public:
    void registerAlgorithm(
        std::shared_ptr<Algorithm> algorithm
    );

    std::shared_ptr<Algorithm>
    getAlgorithm(const std::string& name);

    void listAlgorithms() const;
};