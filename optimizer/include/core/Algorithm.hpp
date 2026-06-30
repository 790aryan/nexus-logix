#pragma once

#include <string>

#include "models/AlgorithmInput.hpp"
#include "models/AlgorithmResult.hpp"

class Algorithm
{
public:

    virtual ~Algorithm() = default;

    virtual std::string getName() const = 0;

    virtual AlgorithmResult execute(
        const AlgorithmInput& input
    ) = 0;
};