#pragma once

#include <Graph/Graph.hpp>


class GraphMatrix : public Graph
{
    public:
    GraphMatrix(uint32_t verticies);
    ~GraphMatrix() = default;

    void addEdge(uint32_t startingVertex, uint32_t endVertex, uint32_t weight);
    int32_t getWeight(uint32_t startingVertex, uint32_t endVertex);
    std::vector<Edge> getVertexNeighbours(uint32_t vertex);
    std::vector<Edge> getEdgesList();
    uint32_t getVertexCount();
    void displayGraph();


    private:
    bool areCoordsValid(uint32_t row, uint32_t column);

    uint32_t vertexCount;
    std::vector<std::vector<int32_t>> graphMatrix;
};
