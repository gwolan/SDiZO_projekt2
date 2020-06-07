#include <numeric>
#include <algorithm>
#include <Algorithm/Dijkstra.hpp>
#include <Algorithm/Utils/VerticiesComparator.hpp>


const int32_t Dijkstra::INFINITY = -1;
const int32_t Dijkstra::NO_PREDECESSOR = -2;

void Dijkstra::reset()
{
    // reset variables
    pathLengths.clear();
    predecessors.clear();
    verticiesQueue.clear();
}

Dijkstra::PathCostAndPredecessor Dijkstra::performDijkstra(std::unique_ptr<Graph>& graph, uint32_t beginVertex)
{
    reset();
    startingVertex = beginVertex;

    prepareTablesAndQueue(graph);

    return findShortestsPaths(graph);
}

Dijkstra::PathCostAndPredecessor Dijkstra::findShortestsPaths(std::unique_ptr<Graph>& graph)
{
    while(!verticiesQueue.empty())
    {
        // sort by cost
        updateQueue();

        //get neighbours for current vertex
        uint32_t currentVertex = *verticiesQueue.begin();
        std::vector<Edge> edges = graph->getVertexNeighbours(currentVertex);

        // relax them and assign current vertex as checked
        relaxNeighbours(edges);
        verticiesQueue.pop_front();
    }

    return generateResults();
}

void Dijkstra::prepareTablesAndQueue(std::unique_ptr<Graph>& graph)
{
    // fill verticies with infinite costs and null predecessors
    pathLengths = std::vector<int32_t>(graph->getVertexCount(), INFINITY);
    predecessors = std::vector<int32_t>(graph->getVertexCount(), NO_PREDECESSOR);

    // add 0 cost to starting vertex
    pathLengths[startingVertex] = 0;

    // create queue with verticies
    verticiesQueue = std::deque<uint32_t>(graph->getVertexCount());
    std::iota(verticiesQueue.begin(), verticiesQueue.end(), 0);
}

void Dijkstra::updateQueue()
{
    // sort queue by path costs
    std::sort(verticiesQueue.begin(), verticiesQueue.end(), VerticiesComparator(pathLengths));
}

void Dijkstra::relaxNeighbours(const std::vector<Edge>& edges)
{
    for(const auto& edge : edges)
    {
        // calculate cost from current vertex to its neighbour
        uint32_t cost = static_cast<uint32_t>(pathLengths[edge.start]) + edge.weight;

        // if given cost is lower than currently known - update cost and predecessor for neighbour
        if(cost < static_cast<uint32_t>(pathLengths[edge.end]))
        {
            pathLengths[edge.end] = pathLengths[edge.start] + edge.weight;
            predecessors[edge.end] = edge.start;
        }
    }
}

Dijkstra::PathCostAndPredecessor Dijkstra::generateResults()
{
    PathCostAndPredecessor result;

    result.first = pathLengths;
    result.second = predecessors;

    return result;
}
