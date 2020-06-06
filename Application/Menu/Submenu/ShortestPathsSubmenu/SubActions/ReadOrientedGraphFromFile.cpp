#include <iostream>
#include <Application/Menu/Submenu/ShortestPathsSubmenu/SubActions/ReadOrientedGraphFromFile.hpp>
#include <Graph/Utils/Edge.hpp>
#include <Graph/GraphMatrix.hpp>
#include <Graph/GraphList.hpp>


ReadOrientedGraphFromFile::ReadOrientedGraphFromFile(const std::string& actionName, std::unique_ptr<Graph>& graphMatrixType,
                                                                                    std::unique_ptr<Graph>& graphListType, uint32_t& beginVertex)
    : BaseSubAction(actionName, graphMatrixType, graphListType)
    , fileContent()
    , fileName()
    , file()
    , vertexCount(0)
    , startingVertex(beginVertex)
{ }

void ReadOrientedGraphFromFile::run()
{
    openFile();
    readEdgesCountIfPossible();
    readVertexCountIfPossible();
    readStartingVertexIfPossible();

    if(file.is_open())
    {
        graphMatrix = std::make_unique<GraphMatrix>(vertexCount);
        graphList = std::make_unique<GraphList>();

        fillGraphs();
        file.close();


        std::cout << std::endl;
        std::cout << "Graf pomyslnie wczytany z pliku." << std::endl;
        std::cout << "Liczba wezlow: " << vertexCount << std::endl;
        std::cout << "Liczba krawedzi: " << graphMatrix->getEdgesList().size() << std::endl;
        std::cout << "Wezel startowy: " << startingVertex << std::endl;
        std::cout << std::endl;

        displayGraphs();
    }
    else
    {
        std::cout << "Plik \"" << fileName << "\" nie istnieje!" << std::endl;
        std::cout << std::endl;
    }
}

void ReadOrientedGraphFromFile::openFile()
{
    std::cout << "Podaj nazwe pliku: ";
    std::cin >> fileName;

    file.open(fileName);
}

void ReadOrientedGraphFromFile::readEdgesCountIfPossible()
{
    if(file.is_open())
    {
        file >> fileContent;
        edgesCount = std::atoi(fileContent.c_str());
    }
}

void ReadOrientedGraphFromFile::readVertexCountIfPossible()
{
    if(file.is_open())
    {
        file >> fileContent;
        vertexCount = std::atoi(fileContent.c_str());
    }
}

void ReadOrientedGraphFromFile::readStartingVertexIfPossible()
{
    if(file.is_open())
    {
        file >> fileContent;
        startingVertex = std::atoi(fileContent.c_str());
    }
}

Edge ReadOrientedGraphFromFile::readEdge()
{
    Edge edge;

    file >> fileContent;
    edge.start = std::atoi(fileContent.c_str());
    file >> fileContent;
    edge.end = std::atoi(fileContent.c_str());
    file >> fileContent;
    edge.weight = std::atoi(fileContent.c_str());

    return edge;
}

void ReadOrientedGraphFromFile::fillGraphs()
{
    for(std::size_t edgeId = 0; edgeId < edgesCount; ++edgeId)
    {
        Edge edge = readEdge();

        graphMatrix->addEdge(edge.start, edge.end, edge.weight);
        graphList->addEdge(edge.start, edge.end, edge.weight);
    }
}

void ReadOrientedGraphFromFile::displayGraphs()
{
    std::cout << "Macierz sasiedztwa:" << std::endl;
    graphMatrix->displayGraph();
    std::cout << std::endl;

    std::cout << "Lista sasiedztwa:" << std::endl;
    graphList->displayGraph();
    std::cout << std::endl;
}
