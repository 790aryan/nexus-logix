#include "simulator/InventoryGenerator.hpp"

#include <random>

namespace
{
    const std::vector<std::string> productNames =
    {
        "Wireless Mouse",
        "Mechanical Keyboard",
        "Monitor",
        "USB Cable",
        "SSD",
        "Laptop",
        "Router",
        "Printer"
    };

    const std::vector<std::string> categories =
    {
        "Electronics",
        "Networking",
        "Storage",
        "Accessories"
    };

    const std::vector<std::string> suppliers =
    {
        "Logitech",
        "Dell",
        "HP",
        "Samsung",
        "Seagate",
        "Lenovo"
    };

    std::mt19937 rng(std::random_device{}());
}

Product InventoryGenerator::generateProduct(int id)
{
    std::uniform_int_distribution<> nameDist(0, productNames.size() - 1);
    std::uniform_int_distribution<> categoryDist(0, categories.size() - 1);
    std::uniform_int_distribution<> supplierDist(0, suppliers.size() - 1);
    std::uniform_int_distribution<> quantityDist(10, 500);
    std::uniform_real_distribution<> priceDist(500.0, 50000.0);
    std::uniform_int_distribution<> warehouseDist(1, 10);

    Product product;

    product.id = id;

    product.sku = "SKU-" + std::to_string(100000 + id);

    product.name = productNames[nameDist(rng)];

    product.category = categories[categoryDist(rng)];

    product.price = priceDist(rng);

    product.quantity = quantityDist(rng);

    product.warehouseId = warehouseDist(rng);

    product.supplier = suppliers[supplierDist(rng)];

    return product;
}

std::vector<Product>
InventoryGenerator::generateInventory(
    int totalProducts
)
{
    std::vector<Product> inventory;

    inventory.reserve(totalProducts);

    for(int i = 1; i <= totalProducts; i++)
    {
        inventory.push_back(generateProduct(i));
    }

    return inventory;
}