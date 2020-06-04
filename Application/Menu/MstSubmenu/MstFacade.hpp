#pragma once

#include <string>
#include <memory>
#include <Application/Menu/IOhandler.hpp>
#include <Application/Menu/MstSubmenu/MstStrategy.hpp>


// instance of Facade design pattern
// represents MST submenu


class MstFacade
{
    public:
    MstFacade(const std::string& menuContent);
    ~MstFacade() = default;

    void run();
    void printMenu();
    void readMenuSelection();
    std::string getCurrentMenuSelection();


    private:
    IOhandler ioHandler;
    MstStrategy mstStrategy;
};
