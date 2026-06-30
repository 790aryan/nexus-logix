#pragma once

#include <unordered_map>
#include <vector>
#include <string>

struct AlgorithmInput
{
    std::vector<int> numbers;

    int target = 0;

    int sourceNode = -1;

    int destinationNode = -1;

    std::unordered_map<std::string, std::string> metadata;
};