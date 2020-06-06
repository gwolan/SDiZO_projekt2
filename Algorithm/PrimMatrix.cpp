#include <iostream>
#include <Algorithm/PrimMatrix.hpp>


PrimMatrix::PathCostAndPath PrimMatrix::performPrimOnMatrix(std::unique_ptr<GraphMatrix>& graph, uint32_t startingVertex)
{
    // reset queue
    edgeQueue = EdgeQueue();

    // set flags
    visited.resize(graph->getVertexCount(), false);
    visited[startingVertex] = true;

    // fill queue with neighbours of starting point
    auto startingVertexNeighbours = graph->getVertexNeighbours(startingVertex);
    addEdgesToQueue(startingVertexNeighbours);

    // start algorithm
    auto result = createMst(graph);
    return result;
}

PrimMatrix::PathCostAndPath PrimMatrix::createMst(std::unique_ptr<GraphMatrix>& graph)
{
    PathCostAndPath result;

    while(!edgeQueue.empty())
    {
        // get edge with lowest weight
        auto edge = edgeQueue.top();
        edgeQueue.pop();

        // if target was not visited add MST edge
        if(!visited[edge.end])
        {
            // set flag for vertex as visited
            visited[edge.end] = true;

            // add edge to result
            result.first += edge.weight;
            result.second.push_back(edge);

            // get neighbours of current node and add them to queue
            auto neighbours = graph->getVertexNeighbours(edge.end);
            addEdgesToQueue(neighbours);
        }
    }

    return result;
}

void PrimMatrix::addEdgesToQueue(const std::vector<Edge>& edges)
{
    for(auto& edge : edges)
    {
        edgeQueue.push(edge);
    }
}
