#pragma once

#include <string>
#include <memory>
#include <Application/Menu/IOhandler.hpp>
#include <Application/Menu/MstSubmenu/MstStrategy.hpp>
#include <Graph/GraphMatrix.hpp>
#include <Graph/GraphList.hpp>


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
    std::unique_ptr<GraphMatrix> graphMatrix;
    std::unique_ptr<GraphList> graphList;
    IOhandler ioHandler;
    MstStrategy mstStrategy;
};
