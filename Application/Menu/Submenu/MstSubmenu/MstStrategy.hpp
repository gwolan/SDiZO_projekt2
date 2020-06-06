#pragma once

#include <memory>
#include <Application/Menu/Actions/BaseAction.hpp>
#include <Graph/GraphMatrix.hpp>
#include <Graph/GraphList.hpp>


// instance of Strategy desing pattern
// each strategy is called SubAction
// user has choices in Sub Menu
// each Sub Menu choice defines Sub Menu Action

// MstStrategy class initializes SubAction object based on user choice


class MstStrategy
{
    public:
    MstStrategy(std::unique_ptr<GraphMatrix>& graphMatrixType, std::unique_ptr<GraphList>& graphListType);

    void executeAction();
    bool selectAction(std::string choice);


    public:
    std::unique_ptr<BaseAction> selectedAction;
    std::unique_ptr<GraphMatrix>& graphMatrix;
    std::unique_ptr<GraphList>& graphList;
};
