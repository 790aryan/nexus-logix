#pragma once

#include <vector>

#include "algorithms/trees/SegmentTree.hpp"

class InventoryAnalyticsEngine
{
public:

    explicit InventoryAnalyticsEngine(
        const std::vector<int>& inventory
    );

    int getTotalInventory() const;

    int getInventoryRange(
        int left,
        int right
    ) const;

    void updateInventory(
        int index,
        int value
    );

    double getAverageInventory() const;

    int getMaximumInventory() const;

    int getMinimumInventory() const;

    const std::vector<int>&
    getInventory() const;

private:

    std::vector<int> inventory;

    SegmentTree segmentTree;
};