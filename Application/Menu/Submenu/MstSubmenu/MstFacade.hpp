#pragma once

#include <string>
#include <memory>
#include <Application/Menu/IOhandler.hpp>
#include <Application/Menu/Submenu/MstSubmenu/MstStrategy.hpp>
#include <Graph/Graph.hpp>


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
    std::unique_ptr<Graph> graphMatrix;
    std::unique_ptr<Graph> graphList;
    IOhandler ioHandler;
    MstStrategy mstStrategy;
};
