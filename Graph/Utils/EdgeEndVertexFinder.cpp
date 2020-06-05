#include <Graph/Utils/EdgeEndVertexFinder.hpp>


EdgeEndVertexFinder::EdgeEndVertexFinder(uint32_t vertex)
    : vertexIdToFind(vertex)
{ }

bool EdgeEndVertexFinder::operator()(const EdgeEndVertexFinder::VertexWithWeight& listElement)
{
    if(listElement.first == vertexIdToFind)
    {
        return true;
    }

    return false;
}
