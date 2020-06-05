#pragma once

#include <vector>
#include <cstdint>
#include <utility>
#include <Graph/Utils/Edge.hpp>


class GraphMatrix
{
    private:
    using VertexWithWeight = std::pair<uint32_t, int32_t>;


    public:
    static const int32_t NO_EDGE;

    GraphMatrix(uint32_t verticies);
    ~GraphMatrix() = default;

    void addEdge(uint32_t row, uint32_t column, uint32_t weight);
    int32_t getWeight(uint32_t row, uint32_t column);
    std::vector<VertexWithWeight> getVertexNeighbours(uint32_t vertex);
    std::vector<Edge> getEdgesList();
    uint32_t getVertexCount();
    void displayGraph();


    private:
    bool areCoordsValid(uint32_t row, uint32_t column);

    uint32_t vertexCount;
    std::vector<std::vector<int32_t>> graphMatrix;
};
