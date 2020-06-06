#include <iostream>
#include <Application/Menu/MstSubmenu/SubActions/ReadGraphFromFile.hpp>
#include <Graph/Utils/Edge.hpp>


ReadGraphFromFile::ReadGraphFromFile(const std::string& actionName, std::unique_ptr<GraphMatrix>& graphMatrixType,
                                                                    std::unique_ptr<GraphList>& graphListType)
    : BaseSubAction(actionName, graphMatrixType, graphListType)
    , fileContent()
    , fileName()
    , file()
    , vertexCount(0)
{ }

void ReadGraphFromFile::run()
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


        std::cout << "Graf pomyslnie wczytany z pliku. Liczba wezlow: " << vertexCount << std::endl;
        std::cout << std::endl;

        displayGraphs();
    }
    else
    {
        std::cout << "Plik \"" << fileName << "\" nie istnieje!" << std::endl;
        std::cout << std::endl;
    }
}

void ReadGraphFromFile::openFile()
{
    std::cout << "Podaj nazwe pliku: ";
    std::cin >> fileName;

    file.open(fileName);
}

void ReadGraphFromFile::readEdgesCountIfPossible()
{
    if(file.is_open())
    {
        file >> fileContent;
        edgesCount = std::atoi(fileContent.c_str());
    }
}

void ReadGraphFromFile::readVertexCountIfPossible()
{
    if(file.is_open())
    {
        file >> fileContent;
        vertexCount = std::atoi(fileContent.c_str());
    }
}

Edge ReadGraphFromFile::readEdge()
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

void ReadGraphFromFile::addEdgeToMatrix(Edge& edge)
{
    // for MST graph is not oriented, so edges are added bidirectionaly
    graphMatrix->addEdge(edge.start, edge.end, edge.weight);
    graphMatrix->addEdge(edge.end, edge.start, edge.weight);
}

void ReadGraphFromFile::addEdgeToList(Edge& edge)
{
    // for MST graph is not oriented, so edges are added bidirectionaly
    graphList->addEdge(edge.start, edge.end, edge.weight);
    graphList->addEdge(edge.end, edge.start, edge.weight);
}

void ReadGraphFromFile::fillGraphs()
{
    for(std::size_t edgeId = 0; edgeId < edgesCount; ++edgeId)
    {
        Edge edge = readEdge();

        addEdgeToMatrix(edge);
        addEdgeToList(edge);
    }
}

void ReadGraphFromFile::displayGraphs()
{
    std::cout << "Macierz sasiedztwa:" << std::endl;
    graphMatrix->displayGraph();
    std::cout << std::endl;

    std::cout << "Lista sasiedztwa:" << std::endl;
    graphList->displayGraph();
    std::cout << std::endl;
}
