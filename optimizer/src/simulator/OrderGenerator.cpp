#include "simulator/OrderGenerator.hpp"

#include <random>

std::vector<Order>
OrderGenerator::generateOrders(
    int count,
    const std::vector<Warehouse>& warehouses,
    const std::vector<Product>& products
)
{
    std::vector<Order> orders;

    if (warehouses.empty() || products.empty())
    {
        return orders;
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<>
        warehouseDist(
            0,
            static_cast<int>(warehouses.size()) - 1
        );

    std::uniform_int_distribution<>
        productDist(
            0,
            static_cast<int>(products.size()) - 1
        );

    std::uniform_int_distribution<>
        quantityDist(
            1,
            20
        );

    std::uniform_real_distribution<>
        weightDist(
            0.5,
            25.0
        );

    for(int i = 1; i <= count; i++)
    {
        int source =
            warehouseDist(gen);

        int destination =
            warehouseDist(gen);

        while(destination == source)
        {
            destination =
                warehouseDist(gen);
        }

        const Product& product =
            products[
                productDist(gen)
            ];

        Order order;

        order.id = i;

        order.sourceWarehouseId =
            warehouses[source].id;

        order.destinationWarehouseId =
            warehouses[destination].id;

        order.productId =
            product.id;

        order.quantity =
            quantityDist(gen);

        order.weight =
            weightDist(gen);

        order.status =
            "Pending";

        orders.push_back(order);
    }

    return orders;
}