#pragma once

#include <memory>
#include <Application/Menu/Actions/BaseAction.hpp>


// instance of Strategy desing pattern
// each strategy is called SubAction
// user has choices in Sub Menu
// each Sub Menu choice defines Sub Menu Action

// MstStrategy class initializes SubAction object based on user choice


class MstStrategy
{
    public:
    MstStrategy();

    void executeAction();
    bool selectAction(std::string choice);


    public:
    std::unique_ptr<BaseAction> selectedAction;
};
