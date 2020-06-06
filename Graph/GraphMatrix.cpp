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

std::vector<Edge> GraphMatrix::getVertexNeighbours(uint32_t vertex)
{
    std::vector<Edge> neighbours;

    for(uint32_t neighbour = 0; neighbour < vertexCount; ++neighbour)
    {
        if(graphMatrix[vertex][neighbour] != NO_EDGE)
        {
            Edge edgeToNeighbour;
            edgeToNeighbour.start = vertex;
            edgeToNeighbour.end = neighbour;
            edgeToNeighbour.weight = graphMatrix[vertex][neighbour];

            neighbours.push_back(edgeToNeighbour);
        }
    }

    return neighbours;
}

std::vector<Edge> GraphMatrix::getEdgesList()
{
    std::vector<Edge> edges;

    for(uint32_t startingVertex = 0; startingVertex < vertexCount; ++startingVertex)
    {
        for(uint32_t endingVertex = 0; endingVertex < vertexCount; ++endingVertex)
        {
            if(graphMatrix[startingVertex][endingVertex] != NO_EDGE)
            {
                Edge edge;
                edge.start = startingVertex;
                edge.end = endingVertex;
                edge.weight = graphMatrix[startingVertex][endingVertex];

                edges.push_back(edge);
            }
        }
    }

    return edges;
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
            if(cell != NO_EDGE)
            {
                std::cout << cell << '\t';
            }
            else
            {
                std::cout << 'X' << '\t';
            }
        }

        std::cout << std::endl;
    }
}
