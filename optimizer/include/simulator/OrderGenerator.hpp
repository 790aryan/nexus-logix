#pragma once

#include <vector>

#include "simulator/Order.hpp"
#include "simulator/Warehouse.hpp"
#include "simulator/Product.hpp"

class OrderGenerator
{
public:

    std::vector<Order> generateOrders(
        int count,
        const std::vector<Warehouse>& warehouses,
        const std::vector<Product>& products
    );
};