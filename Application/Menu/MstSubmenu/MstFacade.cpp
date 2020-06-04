#include <Application/Menu/MstSubmenu/MstFacade.hpp>


MstFacade::MstFacade(const std::string& menuContent)
    : ioHandler(menuContent)
    , mstStrategy()
{ }

void MstFacade::printMenu()
{
    ioHandler.printMenu();
}

void MstFacade::readMenuSelection()
{
    ioHandler.readMenuSelection();
}

std::string MstFacade::getCurrentMenuSelection()
{
    return ioHandler.getCurrentMenuSelection();
}

void MstFacade::run()
{
    // if selected action is supported -> execute it
    if(mstStrategy.selectAction(ioHandler.getCurrentMenuSelection()))
    {
        mstStrategy.executeAction();
    }
}
