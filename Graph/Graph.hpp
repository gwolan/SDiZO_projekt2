#pragma once

#include <vector>
#include <cstdint>
#include <utility>
#include <Graph/Utils/Edge.hpp>


class Graph
{
    public:
    using VertexWithWeight = std::pair<uint32_t, int32_t>;

    static const int32_t NO_EDGE;

    Graph() = default;
    virtual ~Graph() = default;

    virtual void addEdge(uint32_t startingVertex, uint32_t endVertex, uint32_t weight) = 0;
    virtual int32_t getWeight(uint32_t startingVertex, uint32_t endVertex) = 0;
    virtual std::vector<Edge> getVertexNeighbours(uint32_t vertex) = 0;
    virtual std::vector<Edge> getEdgesList() = 0;
    virtual uint32_t getVertexCount() = 0;
    virtual void displayGraph() = 0;
};
