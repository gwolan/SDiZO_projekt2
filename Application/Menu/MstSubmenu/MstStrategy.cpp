#include <iostream>
#include <cstdint>
#include <Application/Menu/MstSubmenu/MstStrategy.hpp>
#include <Application/Menu/Actions/ExitProgram.hpp>


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
            selectedAction = std::make_unique<ExitProgram>("Powrót do glownego Menu");
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