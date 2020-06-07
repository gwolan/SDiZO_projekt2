#pragma once

#include <Application/Menu/Actions/BaseSubAction.hpp>
#include <Algorithm/Dijkstra.hpp>
#include <Miscellanous/Timer.hpp>


class PerformDijkstra : public BaseSubAction
{
    public:
    using DijkstraResults = std::pair<double, Dijkstra::PathCostAndPredecessor>;

    PerformDijkstra(const std::string& actionName, std::unique_ptr<Graph>& graphMatrixType,
                                                   std::unique_ptr<Graph>& graphListType, uint32_t& beginVertex);
    ~PerformDijkstra() = default;

    void run();

    private:
    void displayResults(const DijkstraResults& result, const std::string graphVersion);
    DijkstraResults runDijkstraForMatrix();
    DijkstraResults runDijkstraForList();

    Dijkstra dijkstra;
    Timer timer;
    uint32_t& startingVertex;
};
