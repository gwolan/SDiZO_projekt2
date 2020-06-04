#pragma once

#include <string>
#include <memory>
#include <Application/Menu/IOhandler.hpp>
#include <Application/Menu/ActionStrategy.hpp>


// instance of Facade design pattern
// represent whole application interface


class ApplicationFacade
{
    public:
    ApplicationFacade(const std::string& menuContent);
    ~ApplicationFacade() = default;

    void run();
    void printMenu();
    void readMenuSelection();
    std::string getCurrentMenuSelection();


    private:
    IOhandler ioHandler;
    ActionStrategy actionStrategy;
};
