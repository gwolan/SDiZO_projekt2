#include <iostream>
#include <Application/Menu/Submenu/SharedSubActions/DisplayGraph.hpp>


DisplayGraph::DisplayGraph(const std::string& actionName, std::unique_ptr<GraphMatrix>& graphMatrixType,
                                                          std::unique_ptr<GraphList>& graphListType)
    : BaseSubAction(actionName, graphMatrixType, graphListType)
{ }

void DisplayGraph::run()
{
    if(graphMatrix.get() && graphList.get())
    {
        std::cout << "Macierz sasiedztwa:" << std::endl;
        graphMatrix->displayGraph();
        std::cout << std::endl;

        std::cout << "Lista sasiedztwa:" << std::endl;
        graphList->displayGraph();
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Graf jest pusty." << std::endl;
    }
}
