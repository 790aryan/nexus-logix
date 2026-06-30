#pragma once

#include <string>
#include <unordered_map>
#include <vector>

struct AlgorithmInput
{
    std::vector<int> numbers;

    int target = 0;

    std::unordered_map<std::string, std::string> metadata;
};