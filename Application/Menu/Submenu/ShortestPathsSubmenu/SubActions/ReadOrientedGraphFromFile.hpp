#pragma once

#include <fstream>
#include <Application/Menu/Actions/BaseSubAction.hpp>


class ReadOrientedGraphFromFile : public BaseSubAction
{
    public:
    ReadOrientedGraphFromFile(const std::string& actionName, std::unique_ptr<GraphMatrix>& graphMatrixType,
                                                             std::unique_ptr<GraphList>& graphListType, uint32_t& beginVertex);
    ~ReadOrientedGraphFromFile() = default;

    void run();


    private:
    void openFile();
    void readEdgesCountIfPossible();
    void readVertexCountIfPossible();
    void readStartingVertexIfPossible();
    Edge readEdge();
    void fillGraphs();
    void displayGraphs();

    std::string fileContent;
    std::string fileName;
    std::ifstream file;
    uint32_t edgesCount;
    uint32_t vertexCount;
    uint32_t& startingVertex;
};
