#pragma once

#include <cstdint>
#include <utility>
#include <list>


struct EdgeEndVertexFinder
{
    private:
    using VertexWithWeight = std::pair<uint32_t, int32_t>;


    public:
    EdgeEndVertexFinder(uint32_t vertex);

    bool operator()(const VertexWithWeight& listElement);


    private:
    uint32_t vertexIdToFind;
};
