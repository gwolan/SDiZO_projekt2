#include <iostream>
#include <algorithm>
#include <Graph/GraphList.hpp>
#include <Graph/Utils/VertexOnListFinder.hpp>
#include <Graph/Utils/EdgeEndVertexFinder.hpp>


const int32_t GraphList::NO_EDGE = -1;

void GraphList::addEdge(uint32_t startingVertex, uint32_t endVertex, uint32_t weight)
{
    auto it = std::find_if(graphList.begin(), graphList.end(), VertexOnListFinder(startingVertex));

    if(it == graphList.end())
    {
        VertexWithNeighbours newConnection(startingVertex, std::list<VertexWithWeight>());
        newConnection.second.push_back(VertexWithWeight(endVertex, weight));

        graphList.push_back(newConnection);
        verticies.insert(startingVertex);
    }
    else
    {
        it->second.push_back(VertexWithWeight(endVertex, weight));
    }

    verticies.insert(endVertex);
}

int32_t GraphList::getWeight(uint32_t startingVertex, uint32_t endVertex)
{
    auto it = std::find_if(graphList.begin(), graphList.end(), VertexOnListFinder(startingVertex));

    if(it != graphList.end())
    {
        auto endVertexIt = std::find_if(it->second.begin(), it->second.end(), EdgeEndVertexFinder(endVertex));

        if(endVertexIt != it->second.end())
        {
            return endVertexIt->second;
        }
    }

    return GraphList::NO_EDGE;
}

std::vector<Edge> GraphList::getVertexNeighbours(uint32_t vertex)
{
    std::vector<Edge> neighbours;
    auto it = std::find_if(graphList.begin(), graphList.end(), VertexOnListFinder(vertex));

    if(it != graphList.end())
    {
        for(auto& neighbour : it->second)
        {
            Edge edgeToNeighbour;
            edgeToNeighbour.start = vertex;
            edgeToNeighbour.end = neighbour.first;
            edgeToNeighbour.weight = neighbour.second;

            neighbours.push_back(edgeToNeighbour);
        }
    }

    return neighbours;
}

std::vector<Edge> GraphList::getEdgesList()
{
    std::vector<Edge> edges;

    for(auto& row : graphList)
    {
        for(auto& neighbour : row.second)
        {
            Edge edge;
            edge.start = row.first;
            edge.end = neighbour.first;
            edge.weight = neighbour.second;

            edges.push_back(edge);
        }
    }

    return edges;
}

uint32_t GraphList::getVertexCount()
{
    return verticies.size();
}

void GraphList::displayGraph()
{
    for(auto& row : graphList)
    {
        std::cout << row.first << " : ";

        for(auto& neighbour : row.second)
        {
            std::cout << "{" << neighbour.first << ", " << neighbour.second << "} ";
        }

        std::cout << std::endl;
    }
}
