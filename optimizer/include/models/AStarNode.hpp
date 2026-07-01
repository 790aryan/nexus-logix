#pragma once

struct AStarNode
{
    int nodeId = -1;

    double gCost = 0.0;

    double hCost = 0.0;

    double fCost = 0.0;

    bool operator>(
        const AStarNode& other
    ) const
    {
        return fCost > other.fCost;
    }
};