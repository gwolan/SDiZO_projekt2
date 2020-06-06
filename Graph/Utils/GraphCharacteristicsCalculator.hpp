#pragma once

#include <cstdint>


class GraphCharacteristicsCalculator
{
    public:
    GraphCharacteristicsCalculator(uint32_t verticies, double density);

    uint32_t getMinEdgesNeededToCreateSpanningTree();
    uint32_t getMaxPossibleEdges();
    uint32_t getNumberOfExpectedEdges();


    private:
    uint32_t calculateMinEdgesNeededToCreateSpanningTree(uint32_t verticies);
    uint32_t calculateMaxPossibleEdges(uint32_t verticies);
    uint32_t calculateNumberOfExpectedEdges(uint32_t verticies, double density);

    uint32_t minEdgesNeededToCreateSpanningTree;
    uint32_t maxPossibleEdges;
    uint32_t numberOfExpectedEdges;
};
