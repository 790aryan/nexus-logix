#include "algorithms/graph/DijkstraAlgorithm.hpp"

#include <queue>
#include <unordered_map>
#include <limits>
#include <algorithm>

#include "models/DijkstraState.hpp"

std::string DijkstraAlgorithm::getName() const
{
    return "Dijkstra";
}

void DijkstraAlgorithm::setGraph(
    const WarehouseGraph& graphRef)
{
    graph = &graphRef;
}

AlgorithmResult
DijkstraAlgorithm::execute(
    const AlgorithmInput& input)
{
    AlgorithmResult result;

    result.algorithmName = getName();

    if(graph == nullptr)
    {
        result.message = "Graph not initialized.";
        return result;
    }

    if(input.sourceNode == -1 ||
       input.destinationNode == -1)
    {
        result.message = "Invalid source/destination.";
        return result;
    }

    std::priority_queue<
        DijkstraState,
        std::vector<DijkstraState>,
        std::greater<DijkstraState>
    > pq;

    std::unordered_map<int,double> distance;
    std::unordered_map<int,int> parent;

    for(const auto& entry :
        graph->getAdjacencyList())
    {
        distance[entry.first] =
            std::numeric_limits<double>::infinity();
    }

    distance[input.sourceNode] = 0.0;

    pq.push({
        input.sourceNode,
        0.0
    });

    while(!pq.empty())
    {
        DijkstraState current = pq.top();
        pq.pop();

        if(current.distance >
           distance[current.node])
        {
            continue;
        }

        for(const Road& road :
            graph->getNeighbors(current.node))
        {
            double newDistance =
                distance[current.node] +
                road.distanceKm;

            if(newDistance <
               distance[road.destinationWarehouseId])
            {
                distance[
                    road.destinationWarehouseId
                ] = newDistance;

                parent[
                    road.destinationWarehouseId
                ] = current.node;

                pq.push({
                    road.destinationWarehouseId,
                    newDistance
                });
            }
        }
    }

    if(distance[input.destinationNode] ==
       std::numeric_limits<double>::infinity())
    {
        result.message = "No path found.";
        return result;
    }

    result.shortestDistance =
        distance[input.destinationNode];

    int current =
        input.destinationNode;

    while(current != input.sourceNode)
    {
        result.shortestPath.push_back(current);
        current = parent[current];
    }

    result.shortestPath.push_back(
        input.sourceNode
    );

    std::reverse(
        result.shortestPath.begin(),
        result.shortestPath.end()
    );

    result.success = true;

    result.message =
        "Shortest path computed.";

    return result;
}