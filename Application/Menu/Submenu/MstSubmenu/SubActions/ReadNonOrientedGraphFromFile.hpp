#pragma once

#include <fstream>
#include <Application/Menu/Actions/BaseSubAction.hpp>


class ReadNonOrientedGraphFromFile : public BaseSubAction
{
    public:
    ReadNonOrientedGraphFromFile(const std::string& actionName, std::unique_ptr<Graph>& graphMatrixType,
                                                                std::unique_ptr<Graph>& graphListType);
    ~ReadNonOrientedGraphFromFile() = default;

    void run();


    private:
    uint32_t nonOrientedGraphEdgeCount(const std::vector<Edge>& edgesList);
    void openFile();
    void readEdgesCountIfPossible();
    void readVertexCountIfPossible();
    Edge readEdge();
    void fillGraphs();
    void addEdgeToMatrix(Edge& edge);
    void addEdgeToList(Edge& edge);
    void displayGraphs();

    std::string fileContent;
    std::string fileName;
    std::ifstream file;
    uint32_t edgesCount;
    uint32_t vertexCount;
};
