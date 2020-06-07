#include <iostream>
#include <cstdint>
#include <Application/Menu/Submenu/ShortestPathsSubmenu/ShortestPathsStrategy.hpp>
#include <Application/Menu/Actions/ExitProgram.hpp>
#include <Application/Menu/Submenu/ShortestPathsSubmenu/SubActions/ReadOrientedGraphFromFile.hpp>
#include <Application/Menu/Submenu/ShortestPathsSubmenu/SubActions/GenerateOrientedRandomGraph.hpp>
#include <Application/Menu/Submenu/ShortestPathsSubmenu/SubActions/PerformDijkstra.hpp>
#include <Application/Menu/Submenu/SharedSubActions/DisplayGraph.hpp>


ShortestPathsStrategy::ShortestPathsStrategy(std::unique_ptr<Graph>& graphMatrixType,
                                             std::unique_ptr<Graph>& graphListType, uint32_t& beginVertex)
    : selectedAction(nullptr)
    , graphMatrix(graphMatrixType)
    , graphList(graphListType)
    , startingVertex(beginVertex)
{ }

void ShortestPathsStrategy::executeAction()
{
    // runs SubAction initialized in ShortestPathsStrategy::selectAction method
    selectedAction->run();
}

bool ShortestPathsStrategy::selectAction(std::string choice)
{
    // variable 'choice' defines switch case that should be executed
    // each case initializes SubAction object that should be performed

    uint32_t selection = std::atoi(choice.c_str());

    switch(selection)
    {
        case 0:
        {
            selectedAction = std::make_unique<ExitProgram>("Powrót do glownego Menu");
        }
        break;
        case 1:
        {
            selectedAction = std::make_unique<ReadOrientedGraphFromFile>("Wczytaj graf z pliku", graphMatrix, graphList, startingVertex);
        }
        break;
        case 2:
        {
            selectedAction = std::make_unique<GenerateOrientedRandomGraph>("Wygeneruj losowy graf", graphMatrix, graphList, startingVertex);
        }
        break;
        case 3:
        {
            selectedAction = std::make_unique<DisplayGraph>("Wyswietl graf", graphMatrix, graphList);
        }
        break;
        case 4:
        {
            selectedAction = std::make_unique<PerformDijkstra>("Wykonaj algorytm Dijkstry", graphMatrix, graphList, startingVertex);
        }
        break;
        default:
        {
            std::cout << "Wybrana opcja nie istnieje." << std::endl << std::endl;
            return false;
        }
    }

    std::cout << "Wybrano - " << selectedAction->getActionName() << std::endl << std::endl;
    return true;
}