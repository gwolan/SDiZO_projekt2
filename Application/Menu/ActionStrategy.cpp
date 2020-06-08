#include <iostream>
#include <cstdint>
#include <Application/Menu/ActionStrategy.hpp>
#include <Application/Menu/Actions/ExitProgram.hpp>
#include <Application/Menu/Actions/MstSubmenu.hpp>
#include <Application/Menu/Actions/ShortestPathsSubmenu.hpp>
#include <Application/Menu/Actions/PerformMeasurements.hpp>


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
            selectedAction = std::make_unique<ExitProgram>("Wyjscie z programu");
        }
        break;
        case 1:
        {
            selectedAction = std::make_unique<MstSubmenu>("Algorytmy znajdowania MST w grafie");
        }
        break;
        case 2:
        {
            selectedAction = std::make_unique<ShortestPathsSubmenu>("Algorytmy znajdowania najkrotszych sciezek w grafie");
        }
        break;
        case 3:
        {
            selectedAction = std::make_unique<PerformMeasurements>("Wykonanie pomiarow czasowych");
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