#pragma once

#include <vector>

#include "simulator/Product.hpp"

class InventoryGenerator
{
public:

    std::vector<Product> generateInventory(
        int totalProducts
    );

private:

    Product generateProduct(
        int id
    );
};