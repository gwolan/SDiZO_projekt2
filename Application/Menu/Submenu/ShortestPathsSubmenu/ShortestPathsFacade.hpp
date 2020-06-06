#pragma once

#include <string>
#include <memory>
#include <Application/Menu/IOhandler.hpp>
#include <Application/Menu/Submenu/ShortestPathsSubmenu/ShortestPathsStrategy.hpp>
#include <Graph/Graph.hpp>


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
    std::unique_ptr<Graph> graphMatrix;
    std::unique_ptr<Graph> graphList;
    uint32_t startingVertex;
    IOhandler ioHandler;
    ShortestPathsStrategy shortestPathsStrategy;
};
