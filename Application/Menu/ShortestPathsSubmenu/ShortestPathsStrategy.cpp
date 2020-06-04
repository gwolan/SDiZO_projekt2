#include <iostream>
#include <cstdint>
#include <Application/Menu/ShortestPathsSubmenu/ShortestPathsStrategy.hpp>
#include <Application/Menu/Actions/ExitProgram.hpp>


ShortestPathsStrategy::ShortestPathsStrategy()
    : selectedAction(nullptr)
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
        default:
        {
            std::cout << "Wybrana opcja nie istnieje." << std::endl << std::endl;
            return false;
        }
    }

    std::cout << "Wybrano - " << selectedAction->getActionName() << std::endl << std::endl;
    return true;
}