#pragma once

#include <queue>
#include <utility>
#include <cstdint>
#include <vector>
#include <memory>
#include <Graph/Utils/Edge.hpp>
#include <Graph/GraphMatrix.hpp>
#include <Graph/Utils/EdgeComparator.hpp>


class PrimMatrix
{
    public:
    using PathCostAndPath = std::pair<uint32_t, std::vector<Edge>>;
    using EdgeQueue = std::priority_queue<Edge, std::vector<Edge>, EdgeComparator>;

    PrimMatrix() = default;
    ~PrimMatrix() = default;

    PathCostAndPath performPrimOnMatrix(std::unique_ptr<GraphMatrix>& graph, uint32_t startingVertex);


    private:
    void addEdgesToQueue(const std::vector<Edge>& edges);
    PathCostAndPath createMst(std::unique_ptr<GraphMatrix>& graph);

    std::vector<bool> visited;
    EdgeQueue edgeQueue;
};
