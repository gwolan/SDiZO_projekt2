#pragma once

#include <fstream>
#include <Application/Menu/Actions/BaseSubAction.hpp>


class ReadGraphFromFile : public BaseSubAction
{
    public:
    ReadGraphFromFile(const std::string& actionName, std::unique_ptr<GraphMatrix>& graphMatrixType,
                                                     std::unique_ptr<GraphList>& graphListType);
    ~ReadGraphFromFile() = default;

    void run();


    private:
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
