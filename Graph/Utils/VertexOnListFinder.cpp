#include <Graph/Utils/VertexOnListFinder.hpp>


VertexOnListFinder::VertexOnListFinder(uint32_t vertex)
    : vertexIdToFind(vertex)
{ }

bool VertexOnListFinder::operator()(const VertexOnListFinder::VertexWithNeighbours& listElement)
{
    if(listElement.first == vertexIdToFind)
    {
        return true;
    }

    return false;
}
