#include "algorithms/graph/AStarAlgorithm.hpp"

#include <cmath>
#include <limits>
#include <queue>
#include <unordered_map>
#include <algorithm>

#include "models/AStarNode.hpp"

std::string
AStarAlgorithm::getName() const
{
    return "A*";
}

void AStarAlgorithm::setGraph(
    const WarehouseGraph& graphRef
)
{
    graph = &graphRef;
}

double
AStarAlgorithm::heuristic(
    int currentNode,
    int destinationNode
) const
{
    const Warehouse* current =
        graph->getWarehouse(currentNode);

    const Warehouse* destination =
        graph->getWarehouse(destinationNode);

    if(current == nullptr ||
       destination == nullptr)
    {
        return 0.0;
    }

    double dx =
        current->latitude -
        destination->latitude;

    double dy =
        current->longitude -
        destination->longitude;

    return std::sqrt(
        dx * dx +
        dy * dy
    ) * 111.0;
}

AlgorithmResult
AStarAlgorithm::execute(
    const AlgorithmInput& input
)
{
    AlgorithmResult result;

    result.algorithmName =
        getName();

    if(graph == nullptr)
    {
        result.success = false;
        result.message =
            "Graph not initialized.";

        return result;
    }

    std::priority_queue<
        AStarNode,
        std::vector<AStarNode>,
        std::greater<AStarNode>
    > openSet;

    std::unordered_map<int,double> gCost;

    std::unordered_map<int,int> parent;

    for(const auto& entry :
        graph->getAdjacencyList())
    {
        gCost[entry.first] =
            std::numeric_limits<double>::infinity();
    }

    gCost[input.sourceNode] = 0.0;

    openSet.push(
        {
            input.sourceNode,
            0.0,
            heuristic(
                input.sourceNode,
                input.destinationNode
            ),
            heuristic(
                input.sourceNode,
                input.destinationNode
            )
        }
    );

    while(!openSet.empty())
    {
        AStarNode current =
            openSet.top();

        openSet.pop();

        if(current.nodeId ==
           input.destinationNode)
        {
            break;
        }

        for(const auto& road :
            graph->getNeighbors(
                current.nodeId
            ))
        {
            double tentativeCost =
                gCost[current.nodeId] +
                road.distanceKm;

            if(tentativeCost <
               gCost[road.destinationWarehouseId])
            {
                gCost[
                    road.destinationWarehouseId
                ] = tentativeCost;

                parent[
                    road.destinationWarehouseId
                ] = current.nodeId;

                double h =
                    heuristic(
                        road.destinationWarehouseId,
                        input.destinationNode
                    );

                openSet.push(
                    {
                        road.destinationWarehouseId,
                        tentativeCost,
                        h,
                        tentativeCost + h
                    }
                );
            }
        }
    }

    if(gCost[input.destinationNode] ==
       std::numeric_limits<double>::infinity())
    {
        result.success = false;
        result.message =
            "No route found.";

        return result;
    }

    std::vector<int> path;

    int current =
        input.destinationNode;

    while(current != input.sourceNode)
    {
        path.push_back(current);

        current = parent[current];
    }

    path.push_back(
        input.sourceNode
    );

    std::reverse(
        path.begin(),
        path.end()
    );

    result.success = true;

    result.message =
        "Shortest path computed.";

    result.shortestDistance =
        gCost[input.destinationNode];

    result.shortestPath = path;

    return result;
}