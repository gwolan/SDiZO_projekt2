#pragma once

#include <deque>
#include <utility>
#include <cstdint>
#include <vector>
#include <memory>
#include <Graph/Graph.hpp>
#include <Graph/Utils/Edge.hpp>


class Dijkstra
{
    public:
    using PathCostAndPredecessor = std::pair<std::vector<int32_t>, std::vector<int32_t>>;

    static const int32_t INFINITY;
    static const int32_t NO_PREDECESSOR;

    Dijkstra() = default;
    ~Dijkstra() = default;

    PathCostAndPredecessor performDijkstra(std::unique_ptr<Graph>& graph, uint32_t beginVertex);
    void reset();


    private:
    PathCostAndPredecessor findShortestsPaths(std::unique_ptr<Graph>& graph);
    PathCostAndPredecessor generateResults();
    void prepareTablesAndQueue(std::unique_ptr<Graph>& graph);
    void updateQueue();
    void relaxNeighbours(const std::vector<Edge>& edges);
    void displayQueue();
    void displayTable();

    uint32_t startingVertex;
    std::vector<int32_t> pathLengths;
    std::vector<int32_t> predecessors;
    std::deque<uint32_t> verticiesQueue;
};
