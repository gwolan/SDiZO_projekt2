#pragma once

#include <vector>
#include <Application/Menu/Actions/BaseSubAction.hpp>
#include <Graph/Utils/Edge.hpp>


class GenerateOrientedRandomGraph : public BaseSubAction
{
    public:
    GenerateOrientedRandomGraph(const std::string& actionName, std::unique_ptr<GraphMatrix>& graphMatrixType,
                                                               std::unique_ptr<GraphList>& graphListType, uint32_t& beginVertex);
    ~GenerateOrientedRandomGraph() = default;

    void run();


    private:
    void readVerticiesAndDensity();
    void generateSpanningTree();
    void fillRestOfTheGraph(uint32_t numberOfExpectedEdges);
    void addEdgeIfPossible(std::vector<Edge>& edgesList, Edge& edge);
    void displayGraphs();

    uint32_t vertexCount;
    double graphDensity;
    uint32_t& startingVertex;
};