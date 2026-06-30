#pragma once

#include <string>

struct Product
{
    int id;

    std::string sku;

    std::string name;

    std::string category;

    double price;

    int quantity;

    int warehouseId;

    std::string supplier;
};