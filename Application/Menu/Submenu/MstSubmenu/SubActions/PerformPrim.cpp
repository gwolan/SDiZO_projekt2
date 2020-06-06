#include <iostream>
#include <Application/Menu/Submenu/MstSubmenu/SubActions/PerformPrim.hpp>


PerformPrim::PerformPrim(const std::string& actionName, std::unique_ptr<GraphMatrix>& graphMatrixType,
                                                        std::unique_ptr<GraphList>& graphListType)
    : BaseSubAction(actionName, graphMatrixType, graphListType)
    , primMatrix()
{ }

void PerformPrim::run()
{
    if(graphMatrix.get() && graphList.get())
    {
        timer.start();
        auto result = primMatrix.performPrimOnMatrix(graphMatrix, 0);
        timer.stop();

        displayResults(result);
    }
    else
    {
        std::cout << "Graf jest pusty." << std::endl;
    }
}

void PerformPrim::displayResults(PrimMatrix::PathCostAndPath& result)
{
    std::cout << "Czas trwania algorytmu [s]: " << timer.getTime() << std::endl << std::endl;
    std::cout << "Koszt sumaryczny: " << result.first << std::endl;
    std::cout << "Krawedzie: " << std::endl;

    for(auto edge : result.second)
    {
        std::cout << "{" << edge.start << " -" << edge.weight << "-> " << edge.end << "} ";
    }

    std::cout << std::endl << std::endl;
}