#pragma once

#include <cstdint>
#include <utility>
#include <list>


struct VertexOnListFinder
{
    private:
    using VertexWithWeight = std::pair<uint32_t, int32_t>;
    using VertexWithNeighbours = std::pair<uint32_t, std::list<VertexWithWeight>>;


    public:
    VertexOnListFinder(uint32_t vertex);

    bool operator()(const VertexWithNeighbours& listElement);


    private:
    uint32_t vertexIdToFind;
};
