#include <iostream>
#include <numeric>
#include <random>
#include <algorithm>
#include <utility>
#include <Application/Menu/Submenu/ShortestPathsSubmenu/SubActions/GenerateOrientedRandomGraph.hpp>
#include <Graph/Utils/GraphCharacteristicsCalculator.hpp>
#include <Miscellanous/Dice.hpp>


GenerateOrientedRandomGraph::GenerateOrientedRandomGraph(const std::string& actionName, std::unique_ptr<GraphMatrix>& graphMatrixType,
                                                                                        std::unique_ptr<GraphList>& graphListType, uint32_t& beginVertex)
    : BaseSubAction(actionName, graphMatrixType, graphListType)
    , vertexCount(0)
    , graphDensity(0.0)
    , startingVertex(beginVertex)
{ }

void GenerateOrientedRandomGraph::run()
{
    readVerticiesAndDensity();
    GraphCharacteristicsCalculator graphCharacteristics(vertexCount, graphDensity);

    if(graphCharacteristics.getNumberOfExpectedEdges() >= graphCharacteristics.getMinEdgesNeededToCreateSpanningTree())
    {
        graphMatrix = std::make_unique<GraphMatrix>(vertexCount);
        graphList = std::make_unique<GraphList>();

        generateSpanningTree();
        fillRestOfTheGraph(graphCharacteristics.getNumberOfExpectedEdges());

        std::cout << std::endl;
        std::cout << "Wygenerowano graf:" << std::endl;
        std::cout << "- gestosc: " << graphDensity << "%" << std::endl;
        std::cout << "- ilosc wierzcholkow: " << vertexCount << std::endl;
        std::cout << "- wierzcholek startowy: " << startingVertex << std::endl;
        std::cout << "- ilosc krawedzi: " << graphMatrix->getEdgesList().size() << std::endl;
        std::cout << std::endl;

        displayGraphs();
    }
    else
    {
        std::cout << std::endl;
        std::cout << "Podana ilość wierzcholkow oraz gestosc definuje za mala ilosc krawedzi zeby moc utworzyc drzewo spinajace w grafie:" << std::endl;
        std::cout << "- gestosc: " << graphDensity << "%" << std::endl;
        std::cout << "- ilosc wierzcholkow: " << vertexCount << std::endl;
        std::cout << "- ilosc krawedzi potrzebna do stworzenia drzewa spinajacego: " << graphCharacteristics.getMinEdgesNeededToCreateSpanningTree() << std::endl;
        std::cout << "- rzadana ilosc krawedzi wyliczona na bazie gestosci: " << graphCharacteristics.getNumberOfExpectedEdges() << std::endl;
        std::cout << std::endl;
    }
}

void GenerateOrientedRandomGraph::readVerticiesAndDensity()
{
    std::cout << "Podaj ilosc wierzcholkow: ";
    std::cin >> vertexCount;
    std::cout << "Podaj gestosc [w %]: ";
    std::cin >> graphDensity;
}

void GenerateOrientedRandomGraph::addEdgeIfPossible(std::vector<Edge>& edgesList, Edge& edge)
{
    for(auto existingEdge : edgesList)
    {
        if(existingEdge == edge)
        {
            return;
        }
    }

    graphMatrix->addEdge(edge.start, edge.end, edge.weight);
    graphList->addEdge(edge.start, edge.end, edge.weight);
}

void GenerateOrientedRandomGraph::generateSpanningTree()
{
    // generate list of verticies
    std::vector<uint32_t> verticies(vertexCount);
    std::iota(verticies.begin(), verticies.end(), 0);

    // randomize the list
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::shuffle(verticies.begin(), verticies.end(), generator);

    // create spanning tree
    auto it = verticies.begin();
    Dice dice(1, 999);

    while(std::next(it) != verticies.end())
    {
        Edge edge;
        edge.start = *it;
        edge.end = *std::next(it);
        edge.weight = dice.rollUnsignedInt();

        graphMatrix->addEdge(edge.start, edge.end, edge.weight);
        graphList->addEdge(edge.start, edge.end, edge.weight);

        it = std::next(it);
    }

    startingVertex = *verticies.begin();
}

void GenerateOrientedRandomGraph::fillRestOfTheGraph(uint32_t numberOfExpectedEdges)
{
    // generate list of verticies
    std::vector<uint32_t> verticies(vertexCount);
    std::iota(verticies.begin(), verticies.end(), 0);

    // prepare generators
    Dice indexDice(0, verticies.size() - 1);
    Dice weightDice(1, 999);

    auto edgesList = graphList->getEdgesList();

    while(edgesList.size() < numberOfExpectedEdges)
    {
        // generate different random indexes to choose pair of verticies
        uint32_t indexStart, indexEnd;
        do
        {
            indexStart = indexDice.rollUnsignedInt();
            indexEnd = indexDice.rollUnsignedInt();
        }
        while(indexStart == indexEnd);

        // create an edge and try to add it to the graph
        Edge edge;
        edge.start = verticies[indexStart];
        edge.end = verticies[indexEnd];
        edge.weight = weightDice.rollUnsignedInt();

        addEdgeIfPossible(edgesList, edge);
        edgesList = graphList->getEdgesList();
    }
}

void GenerateOrientedRandomGraph::displayGraphs()
{
    std::cout << "Macierz sasiedztwa:" << std::endl;
    graphMatrix->displayGraph();
    std::cout << std::endl;

    std::cout << "Lista sasiedztwa:" << std::endl;
    graphList->displayGraph();
    std::cout << std::endl;
}
