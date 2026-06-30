#pragma once

#include "core/Algorithm.hpp"

class BinarySearchAlgorithm : public Algorithm
{
public:
    std::string getName() const override;

    AlgorithmResult execute(
        const AlgorithmInput& input
    ) override;

private:
    int binarySearch(
        const std::vector<int>& numbers,
        int target
    );
};