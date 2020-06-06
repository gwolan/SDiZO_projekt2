#pragma once

#include <set>
#include <list>
#include <Graph/Graph.hpp>


class GraphList : public Graph
{
    public:
    using VertexWithNeighbours = std::pair<uint32_t, std::list<Graph::VertexWithWeight>>;

    GraphList() = default;
    ~GraphList() = default;

    void addEdge(uint32_t startingVertex, uint32_t endVertex, uint32_t weight);
    int32_t getWeight(uint32_t startingVertex, uint32_t endVertex);
    std::vector<Edge> getVertexNeighbours(uint32_t vertex);
    std::vector<Edge> getEdgesList();
    uint32_t getVertexCount();
    void displayGraph();


    private:
    std::list<VertexWithNeighbours> graphList;
    std::set<uint32_t> verticies;
};
