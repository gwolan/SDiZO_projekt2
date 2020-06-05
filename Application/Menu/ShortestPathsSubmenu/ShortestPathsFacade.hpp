#pragma once

#include <string>
#include <memory>
#include <Application/Menu/IOhandler.hpp>
#include <Application/Menu/ShortestPathsSubmenu/ShortestPathsStrategy.hpp>
#include <Graph/GraphMatrix.hpp>
#include <Graph/GraphList.hpp>


// instance of Facade design pattern
// represents shortest paths algorithms submenu


class ShortestPathsFacade
{
    public:
    ShortestPathsFacade(const std::string& menuContent);
    ~ShortestPathsFacade() = default;

    void run();
    void printMenu();
    void readMenuSelection();
    std::string getCurrentMenuSelection();


    private:
    std::unique_ptr<GraphMatrix> graphMatrix;
    std::unique_ptr<GraphList> graphList;
    IOhandler ioHandler;
    ShortestPathsStrategy shortestPathsStrategy;
};
