#pragma once

#include <vector>
#include <Application/Menu/Actions/BaseSubAction.hpp>
#include <Graph/Utils/Edge.hpp>


class GenerateRandomGraph : public BaseSubAction
{
    public:
    GenerateRandomGraph(const std::string& actionName, std::unique_ptr<GraphMatrix>& graphMatrixType,
                                                       std::unique_ptr<GraphList>& graphListType);
    ~GenerateRandomGraph() = default;

    void run();


    private:
    uint32_t nonOrientedGraphEdgeCount(const std::vector<Edge>& edgesList);
    void readVerticiesAndDensity();
    void addEdgeToMatrix(Edge& edge);
    void addEdgeToList(Edge& edge);
    void generateSpanningTree();
    void fillRestOfTheGraph(uint32_t numberOfExpectedEdges);
    void addEdgeIfPossible(std::vector<Edge>& edgesList, Edge& edge);
    void displayGraphs();

    uint32_t vertexCount;
    double graphDensity;
};