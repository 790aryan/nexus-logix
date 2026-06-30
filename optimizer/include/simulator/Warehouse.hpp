#pragma once

#include <string>

struct Warehouse
{
    int id;

    std::string code;

    std::string name;

    std::string city;

    std::string state;

    double latitude;

    double longitude;

    int capacity;

    int currentInventory;
};