#include <iostream>
#include <Application/Menu/Submenu/MstSubmenu/SubActions/PerformPrim.hpp>


PerformPrim::PerformPrim(const std::string& actionName, std::unique_ptr<Graph>& graphMatrixType,
                                                        std::unique_ptr<Graph>& graphListType)
    : BaseSubAction(actionName, graphMatrixType, graphListType)
    , prim()
{ }

void PerformPrim::run()
{
    if(graphMatrix.get() && graphList.get())
    {
        PrimResults resultsForMatrix = runPrimForMatrix();
        PrimResults resultsForList = runPrimForList();

        displayResults(resultsForMatrix, "Macierz sasiedztwa");
        displayResults(resultsForList, "Lista sasiedztwa");
    }
    else
    {
        std::cout << "Graf jest pusty." << std::endl;
    }
}

PerformPrim::PrimResults PerformPrim::runPrimForMatrix()
{
    prim.reset();

    timer.start();
    auto result = prim.performPrim(graphMatrix, 0);
    timer.stop();

    return PrimResults(timer.getTime(), result);
}

PerformPrim::PrimResults PerformPrim::runPrimForList()
{
    prim.reset();

    timer.start();
    auto result = prim.performPrim(graphList, 0);
    timer.stop();

    return PrimResults(timer.getTime(), result);
}

void PerformPrim::displayResults(PerformPrim::PrimResults& result, const std::string graphVersion)
{
    std::cout << std::endl << "Wersja grafu \"" << graphVersion << "\"" << std::endl;
    std::cout << "Czas trwania algorytmu [s]: " << result.first << std::endl << std::endl;
    std::cout << "Koszt sumaryczny: " << result.second.first << std::endl;
    std::cout << "Krawedzie: " << std::endl;

    for(auto edge : result.second.second)
    {
        std::cout << "{" << edge.start << " -" << edge.weight << "-> " << edge.end << "} ";
    }

    std::cout << std::endl << std::endl;
}
