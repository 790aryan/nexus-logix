#include "testing/GraphTestBuilder.hpp"

WarehouseGraph GraphTestBuilder::buildTestGraph() const
{
    WarehouseGraph graph;

    auto add =
        [&](int from, int to, double distance)
        {
            Road road;

            road.sourceWarehouseId = from;
            road.destinationWarehouseId = to;

            road.distanceKm = distance;
            road.travelTimeMinutes = distance;
            road.trafficFactor = 1.0;

            graph.addRoad(road);

            Road reverse = road;

            reverse.sourceWarehouseId = to;
            reverse.destinationWarehouseId = from;

            graph.addRoad(reverse);
        };

    add(1,2,10);

    add(1,3,5);

    add(3,4,3);

    add(2,4,2);

    return graph;
}