#pragma once

struct Road
{
    int sourceWarehouseId;

    int destinationWarehouseId;

    double distanceKm;

    double travelTimeMinutes;

    double trafficFactor;

    double weight() const
    {
        return distanceKm * trafficFactor;
    }
};