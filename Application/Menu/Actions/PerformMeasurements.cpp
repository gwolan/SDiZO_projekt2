#include <iostream>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <Application/Menu/Actions/PerformMeasurements.hpp>
#include <Graph/GraphMatrix.hpp>
#include <Graph/GraphList.hpp>
#include <Miscellanous/Dice.hpp>
#include <Graph/Utils/GraphCharacteristicsCalculator.hpp>


PerformMeasurements::PerformMeasurements(const std::string& actionName)
    : BaseAction(actionName)
    , generationsCount(100)
    , graphTypes(2)
    , instanceSizes( { 10, 15, 25, 50, 90, 130, 150 } )
    , densities( { 20.0, 60.0, 99.0 } )
{ }

void PerformMeasurements::run()
{
    uint32_t startingVertex;

    for(uint32_t type = 0; type < graphTypes; ++type)
    {
        for(auto& size : instanceSizes)
        {
            for(auto& density : densities)
            {
                double primTimeSummary = 0.0;
                double dijkstraTimeSummary = 0.0;

                for(uint32_t generation = 0; generation < generationsCount; ++generation)
                {
                    prim.reset();
                    dijkstra.reset();
                    generateRandomGraphs(size, startingVertex, density, type);

                    std::cout << "Pomiar dla algorytmu Prim. \tRozmiar " << size << ". Gestosc " << density << "%. Typ: \"" << ((type == 0) ? "Macierz" : "Lista") << "\". " << "Pomiar " << generation + 1 << " z " << generationsCount << "..." << std::endl;
                    timer.start();
                    prim.performPrim(graphNonOriented, startingVertex);
                    timer.stop();
                    primTimeSummary += timer.getTime();

                    std::cout << "Pomiar dla algorytmu Dijkstra. \tRozmiar " << size << ". Gestosc " << density << "%. Typ: \"" << ((type == 0) ? "Macierz" : "Lista") << "\". " << "Pomiar " << generation + 1 << " z " << generationsCount << "..." << std::endl;
                    timer.start();
                    dijkstra.performDijkstra(graphOriented, startingVertex);
                    timer.stop();
                    dijkstraTimeSummary += timer.getTime();
                }

                Result resultForPrim;
                resultForPrim.size = size;
                resultForPrim.density = density;
                resultForPrim.time = primTimeSummary / static_cast<double>(generationsCount);

                Result resultForDijkstra;
                resultForDijkstra.size = size;
                resultForDijkstra.density = density;
                resultForDijkstra.time = dijkstraTimeSummary / static_cast<double>(generationsCount);

                if(type == 0)
                {
                    primMatrixResults.push_back(resultForPrim);
                    dijkstraMatrixResults.push_back(resultForDijkstra);
                }
                else
                {
                    primListResults.push_back(resultForPrim);
                    dijkstraListResults.push_back(resultForDijkstra);
                }
            }
        }
    }

    saveResultsToFile();
}

void PerformMeasurements::saveResultsToFile()
{
    std::ofstream file;
    std::string fileName = "results.txt";

    file.open(fileName);
    file << "Prim" << std::endl;
    file << "Size" << "\t" << "Type" << "\t" << "Dens" << "\t" << "Time" << std::endl;
    for(auto result : primMatrixResults)
    {
        file << result.size << "\t" << "Matr" << "\t" << result.density << "\t" << result.time << std::endl;
    }

    for(auto result : primListResults)
    {
        file << result.size << "\t" << "List" << "\t" << result.density << "\t" << result.time << std::endl;
    }
    file << std::endl;


    file << "Dijkstra" << std::endl;
    file << "Size" << "\t" << "Type" << "\t" << "Dens" << "\t" << "Time" << std::endl;
    for(auto result : dijkstraMatrixResults)
    {
        file << result.size << "\t" << "Matr" << "\t" << result.density << "\t" << result.time << std::endl;
    }

    for(auto result : dijkstraListResults)
    {
        file << result.size << "\t" << "List" << "\t" << result.density << "\t" << result.time << std::endl;
    }

    file.close();
}

void PerformMeasurements::generateRandomGraphs(uint32_t size, uint32_t& startingVertex, double density, uint32_t type)
{
    if(type == 0)
    {
        graphNonOriented = std::make_unique<GraphMatrix>(size);
        graphOriented = std::make_unique<GraphMatrix>(size);
    }
    else
    {
        graphNonOriented = std::make_unique<GraphList>();
        graphOriented = std::make_unique<GraphList>();
    }

    generateSpanningTree(size, startingVertex);
    fillRestOfTheNonOrientedGraph(size, density);
    fillRestOfTheOrientedGraph(size, density);
}

uint32_t PerformMeasurements::nonOrientedGraphEdgeCount(const std::vector<Edge>& edgesList)
{
    return edgesList.size() / 2;
}

void PerformMeasurements::addEdgeToNonOrientedGraph(Edge& edge)
{
    // for MST graph is not oriented, so edges are added bidirectionaly
    graphNonOriented->addEdge(edge.start, edge.end, edge.weight);
    graphNonOriented->addEdge(edge.end, edge.start, edge.weight);
}

void PerformMeasurements::addNonOrientedEdgeIfPossible(std::vector<Edge>& nonOrientedEdgesList, Edge& edge)
{
    for(auto existingEdge : nonOrientedEdgesList)
    {
        if(existingEdge == edge)
        {
            return;
        }
    }

    Edge adjacentEdge;
    adjacentEdge.start = edge.end;
    adjacentEdge.end = edge.start;
    adjacentEdge.weight = edge.weight;

    nonOrientedEdgesList.push_back(edge);
    nonOrientedEdgesList.push_back(adjacentEdge);
    addEdgeToNonOrientedGraph(edge);
}

void PerformMeasurements::addOrientedEdgeIfPossible(std::vector<Edge>& orientedEdgesList, Edge& edge)
{
    for(auto existingEdge : orientedEdgesList)
    {
        if(existingEdge == edge)
        {
            return;
        }
    }

    orientedEdgesList.push_back(edge);
    graphOriented->addEdge(edge.start, edge.end, edge.weight);
}

void PerformMeasurements::generateSpanningTree(uint32_t size, uint32_t& startingVertex)
{
    // generate list of verticies
    std::vector<uint32_t> verticies(size);
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

        addEdgeToNonOrientedGraph(edge);
        graphOriented->addEdge(edge.start, edge.end, edge.weight);

        it = std::next(it);
    }

    startingVertex = *verticies.begin();
}

void PerformMeasurements::fillRestOfTheNonOrientedGraph(uint32_t size, double density)
{
    GraphCharacteristicsCalculator calc(size, density);

    // generate list of verticies
    std::vector<uint32_t> verticies(size);
    std::iota(verticies.begin(), verticies.end(), 0);

    // prepare generators
    Dice indexDice(0, verticies.size() - 1);
    Dice weightDice(1, 999);

    auto nonOrientedEdgesList = graphNonOriented->getEdgesList();

    while(nonOrientedGraphEdgeCount(nonOrientedEdgesList) < calc.getNumberOfExpectedEdges())
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

        addNonOrientedEdgeIfPossible(nonOrientedEdgesList, edge);
    }
}

void PerformMeasurements::fillRestOfTheOrientedGraph(uint32_t size, double density)
{
    GraphCharacteristicsCalculator calc(size, density);

    // generate list of verticies
    std::vector<uint32_t> verticies(size);
    std::iota(verticies.begin(), verticies.end(), 0);

    // prepare generators
    Dice indexDice(0, verticies.size() - 1);
    Dice weightDice(1, 999);

    auto orientedEdgesList = graphOriented->getEdgesList();

    while(orientedEdgesList.size() < calc.getNumberOfExpectedEdges())
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

        addOrientedEdgeIfPossible(orientedEdgesList, edge);
    }
}
