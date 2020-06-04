#pragma once

#include <string>
#include <Application/Menu/Actions/BaseAction.hpp>


// This Action is responsible for sub menu related to MST algorithm interactions


class MstSubmenu : public BaseAction
{
    public:
    MstSubmenu(const std::string& actionName);

    void run();
};
