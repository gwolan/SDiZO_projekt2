#pragma once

#include <Application/Menu/Actions/BaseAction.hpp>


// This Action is just an empty instance to initialize at program termination


class ExitProgram : public BaseAction
{
    public:
    ExitProgram(const std::string& actionName);

    void run();
};
