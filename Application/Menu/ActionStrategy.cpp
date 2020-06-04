#include <iostream>
#include <cstdint>
#include <Application/Menu/ActionStrategy.hpp>
#include <Application/Menu/Actions/ExitProgram.hpp>


ActionStrategy::ActionStrategy()
    : selectedAction(nullptr)
{ }

void ActionStrategy::executeAction()
{
    // runs Action initialized in ActionStrategy::selectAction method
    selectedAction->run();
}

bool ActionStrategy::selectAction(std::string choice)
{
    // variable 'choice' defines switch case that should be executed
    // each case initializes Action object that should be performed

    uint32_t selection = std::atoi(choice.c_str());

    switch(selection)
    {
        case 0:
        {
            selectedAction = std::make_unique<ExitProgram>("Wyjście z programu");
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