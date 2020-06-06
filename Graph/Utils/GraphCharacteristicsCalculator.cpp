#include <Graph/Utils/GraphCharacteristicsCalculator.hpp>


GraphCharacteristicsCalculator::GraphCharacteristicsCalculator(uint32_t verticies, double density)
    : minEdgesNeededToCreateSpanningTree(calculateMinEdgesNeededToCreateSpanningTree(verticies))
    , maxPossibleEdges(calculateMaxPossibleEdges(verticies))
    , numberOfExpectedEdges(calculateNumberOfExpectedEdges(verticies, density / 100.0))
{ }

uint32_t GraphCharacteristicsCalculator::calculateMinEdgesNeededToCreateSpanningTree(uint32_t verticies)
{
    return verticies - 1;
}

uint32_t GraphCharacteristicsCalculator::calculateMaxPossibleEdges(uint32_t verticies)
{
    return (verticies*(verticies-1)) / 2;
}

uint32_t GraphCharacteristicsCalculator::calculateNumberOfExpectedEdges(uint32_t verticies, double density)
{
    return static_cast<uint32_t>((density * static_cast<double>(verticies*(verticies-1))) / 2.0);
}

uint32_t GraphCharacteristicsCalculator::getMinEdgesNeededToCreateSpanningTree()
{
    return minEdgesNeededToCreateSpanningTree;
}

uint32_t GraphCharacteristicsCalculator::getMaxPossibleEdges()
{
    return maxPossibleEdges;
}

uint32_t GraphCharacteristicsCalculator::getNumberOfExpectedEdges()
{
    return numberOfExpectedEdges;
}
