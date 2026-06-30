#include "algorithms/search/BinarySearchAlgorithm.hpp"

std::string BinarySearchAlgorithm::getName() const
{
    return "Binary Search";
}

int BinarySearchAlgorithm::binarySearch(
    const std::vector<int>& numbers,
    int target
)
{
    int left = 0;
    int right = static_cast<int>(numbers.size()) - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (numbers[mid] == target)
            return mid;

        if (numbers[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

AlgorithmResult BinarySearchAlgorithm::execute(
    const AlgorithmInput& input
)
{
    AlgorithmResult result;

    result.algorithmName = getName();

    int index = binarySearch(
        input.numbers,
        input.target
    );

    if (index != -1)
    {
        result.success = true;
        result.message = "Target found.";
        result.output.push_back(index);
    }
    else
    {
        result.success = false;
        result.message = "Target not found.";
    }

    result.metrics.inputSize = input.numbers.size();
    result.metrics.outputSize = result.output.size();

    return result;
}