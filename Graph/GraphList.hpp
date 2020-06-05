#pragma once

#include <set>
#include <list>
#include <vector>
#include <cstdint>
#include <utility>


class GraphList
{
    private:
    using VertexWithWeight = std::pair<uint32_t, int32_t>;
    using VertexWithNeighbours = std::pair<uint32_t, std::list<VertexWithWeight>>;


    public:
    static const int32_t NO_EDGE;

    GraphList() = default;
    ~GraphList() = default;

    void addEdge(uint32_t startingVertex, uint32_t endVertex, uint32_t weight);
    int32_t getWeight(uint32_t startingVertex, uint32_t endVertex);
    std::vector<VertexWithWeight> getVertexNeighbours(uint32_t vertex);
    uint32_t getVertexCount();
    void displayGraph();


    private:
    std::list<VertexWithNeighbours> graphList;
    std::set<uint32_t> verticies;
};
