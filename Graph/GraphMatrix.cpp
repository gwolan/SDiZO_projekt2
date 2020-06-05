#include <iostream>
#include <Graph/GraphMatrix.hpp>


const int32_t GraphMatrix::NO_EDGE = -1;

GraphMatrix::GraphMatrix(uint32_t verticies)
    : vertexCount(verticies)
    , graphMatrix(verticies, std::vector<int32_t>(verticies, NO_EDGE))
{ }

bool GraphMatrix::areCoordsValid(uint32_t row, uint32_t column)
{
    if( row >= vertexCount || column >= vertexCount)
    {
        return false;
    }

    return true;
}

void GraphMatrix::addEdge(uint32_t row, uint32_t column, uint32_t weight)
{
    if(areCoordsValid(row, column))
    {
        graphMatrix[row][column] = weight;
    }
}

int32_t GraphMatrix::getWeight(uint32_t row, uint32_t column)
{
    if(areCoordsValid(row, column))
    {
        return graphMatrix[row][column];
    }
    else
    {
        return 0;
    }
}

std::vector<GraphMatrix::VertexWithWeight> GraphMatrix::getVertexNeighbours(uint32_t vertex)
{
    std::vector<VertexWithWeight> neighbours;

    for(uint32_t neighbour = 0; neighbour < vertexCount; ++neighbour)
    {
        if(graphMatrix[vertex][neighbour] != NO_EDGE)
        {
            VertexWithWeight neighbourWithWeight(neighbour, graphMatrix[vertex][neighbour]);
            neighbours.push_back(neighbourWithWeight);
        }
    }

    return neighbours;
}

uint32_t GraphMatrix::getVertexCount()
{
    return vertexCount;
}

void GraphMatrix::displayGraph()
{
    for(auto& row : graphMatrix)
    {
        for(auto& cell : row)
        {
            std::cout << cell << '\t';
        }

        std::cout << std::endl;
    }
}
