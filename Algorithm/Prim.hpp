#pragma once

#include <queue>
#include <utility>
#include <cstdint>
#include <vector>
#include <memory>
#include <Graph/Graph.hpp>
#include <Graph/Utils/EdgeComparator.hpp>


class Prim
{
    public:
    using PathCostAndPath = std::pair<uint32_t, std::vector<Edge>>;
    using EdgeQueue = std::priority_queue<Edge, std::vector<Edge>, EdgeComparator>;

    Prim() = default;
    ~Prim() = default;

    PathCostAndPath performPrim(std::unique_ptr<Graph>& graph, uint32_t startingVertex);
    void reset();


    private:
    void addEdgesToQueue(const std::vector<Edge>& edges);
    PathCostAndPath createMst(std::unique_ptr<Graph>& graph);

    std::vector<bool> visited;
    EdgeQueue edgeQueue;
};
