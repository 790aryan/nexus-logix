#include "engine/InventoryAnalyticsEngine.hpp"

#include <algorithm>

InventoryAnalyticsEngine::InventoryAnalyticsEngine(
    const std::vector<int>& inventoryData
)
    : inventory(inventoryData),
      segmentTree(inventoryData)
{
}

int InventoryAnalyticsEngine::getTotalInventory() const
{
    if(inventory.empty())
    {
        return 0;
    }

    return segmentTree.query(
        0,
        static_cast<int>(inventory.size()) - 1
    );
}

int InventoryAnalyticsEngine::getInventoryRange(
    int left,
    int right
) const
{
    if(inventory.empty())
    {
        return 0;
    }

    if(left < 0)
    {
        left = 0;
    }

    if(right >= static_cast<int>(inventory.size()))
    {
        right = static_cast<int>(inventory.size()) - 1;
    }

    if(left > right)
    {
        return 0;
    }

    return segmentTree.query(
        left,
        right
    );
}

void InventoryAnalyticsEngine::updateInventory(
    int index,
    int value
)
{
    if(index < 0 ||
       index >= static_cast<int>(inventory.size()))
    {
        return;
    }

    inventory[index] = value;

    segmentTree.update(
        index,
        value
    );
}

double InventoryAnalyticsEngine::getAverageInventory() const
{
    if(inventory.empty())
    {
        return 0.0;
    }

    return static_cast<double>(
        getTotalInventory()
    ) / inventory.size();
}

int InventoryAnalyticsEngine::getMaximumInventory() const
{
    if(inventory.empty())
    {
        return 0;
    }

    return *std::max_element(
        inventory.begin(),
        inventory.end()
    );
}

int InventoryAnalyticsEngine::getMinimumInventory() const
{
    if(inventory.empty())
    {
        return 0;
    }

    return *std::min_element(
        inventory.begin(),
        inventory.end()
    );
}

const std::vector<int>&
InventoryAnalyticsEngine::getInventory() const
{
    return inventory;
}