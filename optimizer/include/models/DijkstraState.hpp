#pragma once

struct DijkstraState
{
    int node;

    double distance;

    bool operator>(const DijkstraState& other) const
    {
        return distance > other.distance;
    }
};