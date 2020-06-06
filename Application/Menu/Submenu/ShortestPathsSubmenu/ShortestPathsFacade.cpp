#include <Application/Menu/Submenu/ShortestPathsSubmenu/ShortestPathsFacade.hpp>


ShortestPathsFacade::ShortestPathsFacade(const std::string& menuContent)
    : graphMatrix(nullptr)
    , graphList(nullptr)
    , startingVertex(0)
    , ioHandler(menuContent)
    , shortestPathsStrategy(graphMatrix, graphList, startingVertex)
{ }

void ShortestPathsFacade::printMenu()
{
    ioHandler.printMenu();
}

void ShortestPathsFacade::readMenuSelection()
{
    ioHandler.readMenuSelection();
}

std::string ShortestPathsFacade::getCurrentMenuSelection()
{
    return ioHandler.getCurrentMenuSelection();
}

void ShortestPathsFacade::run()
{
    // if selected action is supported -> execute it
    if(shortestPathsStrategy.selectAction(ioHandler.getCurrentMenuSelection()))
    {
        shortestPathsStrategy.executeAction();
    }
}
