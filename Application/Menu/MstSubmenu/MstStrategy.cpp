#include <iostream>
#include <cstdint>
#include <Application/Menu/MstSubmenu/MstStrategy.hpp>
#include <Application/Menu/Actions/ExitProgram.hpp>
#include <Application/Menu/MstSubmenu/SubActions/ReadGraphFromFile.hpp>
#include <Application/Menu/MstSubmenu/SubActions/GenerateRandomGraph.hpp>
#include <Application/Menu/MstSubmenu/SubActions/DisplayGraph.hpp>


MstStrategy::MstStrategy(std::unique_ptr<GraphMatrix>& graphMatrixType, std::unique_ptr<GraphList>& graphListType)
    : selectedAction(nullptr)
    , graphMatrix(graphMatrixType)
    , graphList(graphListType)
{ }

void MstStrategy::executeAction()
{
    // runs SubAction initialized in MstStrategy::selectAction method
    selectedAction->run();
}

bool MstStrategy::selectAction(std::string choice)
{
    // variable 'choice' defines switch case that should be executed
    // each case initializes SubAction object that should be performed

    uint32_t selection = std::atoi(choice.c_str());

    switch(selection)
    {
        case 0:
        {
            selectedAction = std::make_unique<ExitProgram>("Powrot do glownego Menu");
        }
        break;
        case 1:
        {
            selectedAction = std::make_unique<ReadGraphFromFile>("Wczytaj graf z pliku", graphMatrix, graphList);
        }
        break;
        case 2:
        {
            selectedAction = std::make_unique<GenerateRandomGraph>("Wygeneruj losowy graf", graphMatrix, graphList);
        }
        break;
        case 3:
        {
            selectedAction = std::make_unique<DisplayGraph>("Wyswietl graf", graphMatrix, graphList);
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
