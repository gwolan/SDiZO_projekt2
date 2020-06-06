#include <iostream>
#include <Application/Menu/Submenu/MstSubmenu/SubActions/ReadNonOrientedGraphFromFile.hpp>
#include <Graph/Utils/Edge.hpp>


ReadNonOrientedGraphFromFile::ReadNonOrientedGraphFromFile(const std::string& actionName, std::unique_ptr<GraphMatrix>& graphMatrixType,
                                                                                          std::unique_ptr<GraphList>& graphListType)
    : BaseSubAction(actionName, graphMatrixType, graphListType)
    , fileContent()
    , fileName()
    , file()
    , vertexCount(0)
{ }

void ReadNonOrientedGraphFromFile::run()
{
    openFile();
    readEdgesCountIfPossible();
    readVertexCountIfPossible();

    if(file.is_open())
    {
        graphMatrix = std::make_unique<GraphMatrix>(vertexCount);
        graphList = std::make_unique<GraphList>();

        fillGraphs();
        file.close();


        std::cout << std::endl;
        std::cout << "Graf pomyslnie wczytany z pliku." << std::endl;
        std::cout << "Liczba wezlow: " << vertexCount << std::endl;
        std::cout << "Liczba krawedzi: " << nonOrientedGraphEdgeCount(graphMatrix->getEdgesList()) << std::endl;
        std::cout << std::endl;

        displayGraphs();
    }
    else
    {
        std::cout << "Plik \"" << fileName << "\" nie istnieje!" << std::endl;
        std::cout << std::endl;
    }
}

uint32_t ReadNonOrientedGraphFromFile::nonOrientedGraphEdgeCount(const std::vector<Edge>& edgesList)
{
    return edgesList.size() / 2;
}

void ReadNonOrientedGraphFromFile::openFile()
{
    std::cout << "Podaj nazwe pliku: ";
    std::cin >> fileName;

    file.open(fileName);
}

void ReadNonOrientedGraphFromFile::readEdgesCountIfPossible()
{
    if(file.is_open())
    {
        file >> fileContent;
        edgesCount = std::atoi(fileContent.c_str());
    }
}

void ReadNonOrientedGraphFromFile::readVertexCountIfPossible()
{
    if(file.is_open())
    {
        file >> fileContent;
        vertexCount = std::atoi(fileContent.c_str());
    }
}

Edge ReadNonOrientedGraphFromFile::readEdge()
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

void ReadNonOrientedGraphFromFile::addEdgeToMatrix(Edge& edge)
{
    // for MST graph is not oriented, so edges are added bidirectionaly
    graphMatrix->addEdge(edge.start, edge.end, edge.weight);
    graphMatrix->addEdge(edge.end, edge.start, edge.weight);
}

void ReadNonOrientedGraphFromFile::addEdgeToList(Edge& edge)
{
    // for MST graph is not oriented, so edges are added bidirectionaly
    graphList->addEdge(edge.start, edge.end, edge.weight);
    graphList->addEdge(edge.end, edge.start, edge.weight);
}

void ReadNonOrientedGraphFromFile::fillGraphs()
{
    for(std::size_t edgeId = 0; edgeId < edgesCount; ++edgeId)
    {
        Edge edge = readEdge();

        addEdgeToMatrix(edge);
        addEdgeToList(edge);
    }
}

void ReadNonOrientedGraphFromFile::displayGraphs()
{
    std::cout << "Macierz sasiedztwa:" << std::endl;
    graphMatrix->displayGraph();
    std::cout << std::endl;

    std::cout << "Lista sasiedztwa:" << std::endl;
    graphList->displayGraph();
    std::cout << std::endl;
}
