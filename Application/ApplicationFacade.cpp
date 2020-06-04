#include <Application/ApplicationFacade.hpp>


ApplicationFacade::ApplicationFacade(const std::string& menuContent)
    : ioHandler(menuContent)
    , actionStrategy()
{ }

void ApplicationFacade::printMenu()
{
    ioHandler.printMenu();
}

void ApplicationFacade::readMenuSelection()
{
    ioHandler.readMenuSelection();
}

std::string ApplicationFacade::getCurrentMenuSelection()
{
    return ioHandler.getCurrentMenuSelection();
}

void ApplicationFacade::run()
{
    // if selected action is supported -> execute it
    if(actionStrategy.selectAction(ioHandler.getCurrentMenuSelection()))
    {
        actionStrategy.executeAction();
    }
}
