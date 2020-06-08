#pragma once

#include <vector>
#include <cstdint>
#include <Application/Menu/Actions/BaseAction.hpp>
#include <Graph/Graph.hpp>
#include <Graph/Utils/Edge.hpp>
#include <Miscellanous/Timer.hpp>
#include <Algorithm/Prim.hpp>
#include <Algorithm/Dijkstra.hpp>


class PerformMeasurements : public BaseAction
{
    public:
    PerformMeasurements(const std::string& actionName);
    ~PerformMeasurements() = default;

    void run();


    private:
    struct Result
    {
        uint32_t size;
        double density;
        double time;
    };

    void generateRandomGraphs(uint32_t size, uint32_t& startingVertex, double density, uint32_t type);
    void generateSpanningTree(uint32_t size, uint32_t& startingVertex);
    void fillRestOfTheNonOrientedGraph(uint32_t size, double density);
    void fillRestOfTheOrientedGraph(uint32_t size, double density);
    void addEdgeToNonOrientedGraph(Edge& edge);
    void addNonOrientedEdgeIfPossible(std::vector<Edge>& nonOrientedEdgesList, Edge& edge);
    void addOrientedEdgeIfPossible(std::vector<Edge>& orientedEdgesList, Edge& edge);
    uint32_t nonOrientedGraphEdgeCount(const std::vector<Edge>& edgesList);
    void saveResultsToFile();

    const uint32_t generationsCount;
    const uint32_t graphTypes;
    const std::vector<uint32_t> instanceSizes;
    const std::vector<double> densities;
    std::vector<Result> primMatrixResults;
    std::vector<Result> primListResults;
    std::vector<Result> dijkstraMatrixResults;
    std::vector<Result> dijkstraListResults;
    std::unique_ptr<Graph> graphNonOriented;
    std::unique_ptr<Graph> graphOriented;
    Timer timer;
    Prim prim;
    Dijkstra dijkstra;
};
