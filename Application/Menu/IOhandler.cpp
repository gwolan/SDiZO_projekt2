#include <iostream>
#include <Application/Menu/IOhandler.hpp>


IOhandler::IOhandler(const std::string& menuContent)
    : currentSelection()
    , menu(menuContent)
{ }

void IOhandler::printMenu()
{
    std::cout << menu;
}

std::string IOhandler::getCurrentMenuSelection()
{
    // read stored user selection from variable
    return currentSelection;
}

void IOhandler::readMenuSelection()
{
    // reads user selection from console and stores it in variable
    std::cin >> currentSelection;
}

void IOhandler::setMenuContent(const std::string& menuContent)
{
    menu = menuContent;
}
