#include <iostream>
#include <Application/Menu/Submenu/ShortestPathsSubmenu/SubActions/PerformDijkstra.hpp>


PerformDijkstra::PerformDijkstra(const std::string& actionName, std::unique_ptr<Graph>& graphMatrixType,
                                                                std::unique_ptr<Graph>& graphListType, uint32_t& beginVertex)
    : BaseSubAction(actionName, graphMatrixType, graphListType)
    , dijkstra()
    , startingVertex(beginVertex)
{ }

void PerformDijkstra::run()
{
    if(graphMatrix.get() && graphList.get())
    {
        auto resultsMatrix = runDijkstraForMatrix();
        auto resultsList = runDijkstraForList();

        std::cout << std::endl;
        std::cout << "Wezel startowy: " << startingVertex << std::endl;

        displayResults(resultsMatrix, "Macierz sasiedztwa");
        displayResults(resultsList, "Lista sasiedztwa");
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Graf jest pusty." << std::endl;
    }
}

PerformDijkstra::DijkstraResults PerformDijkstra::runDijkstraForMatrix()
{
    dijkstra.reset();

    timer.start();
    auto result = dijkstra.performDijkstra(graphMatrix, startingVertex);
    timer.stop();

    return DijkstraResults(timer.getTime(), result);
}

PerformDijkstra::DijkstraResults PerformDijkstra::runDijkstraForList()
{
    dijkstra.reset();

    timer.start();
    auto result = dijkstra.performDijkstra(graphList, startingVertex);
    timer.stop();

    return DijkstraResults(timer.getTime(), result);
}

void PerformDijkstra::displayResults(const DijkstraResults& result, const std::string graphVersion)
{
    std::cout << std::endl << "Wyniki dla \"" << graphVersion << "\":" << std::endl;

    uint32_t vertex = 0;
    for(auto& cost : result.second.first)
    {
        std::cout << vertex << "[" << cost << "]";

        int32_t predecessor = result.second.second[vertex];
        while(predecessor != Dijkstra::NO_PREDECESSOR)
        {
            std::cout << " -> " << predecessor;
            predecessor = result.second.second[predecessor];
        }

        vertex++;
        std::cout << std::endl;
    }

    std::cout << "Czas trwania [s]: " << result.first << std::endl;
}
