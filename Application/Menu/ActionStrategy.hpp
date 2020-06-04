#pragma once

#include <memory>
#include <Application/Menu/Actions/BaseAction.hpp>


// instance of Strategy desing pattern
// each strategy is called Action
// user has choices in Menu
// each Menu choice defines Application Action

// ActionStrategy class initializes Action object based on user choice


class ActionStrategy
{
    public:
    ActionStrategy();

    void executeAction();
    bool selectAction(std::string choice);


    public:
    std::unique_ptr<BaseAction> selectedAction;
};
