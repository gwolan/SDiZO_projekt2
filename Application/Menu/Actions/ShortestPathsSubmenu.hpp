#pragma once

#include <string>
#include <Application/Menu/Actions/BaseAction.hpp>


// This Action is responsible for sub menu related to finding shortest paths in graph algorithm


class ShortestPathsSubmenu : public BaseAction
{
    public:
    ShortestPathsSubmenu(const std::string& actionName);

    void run();
};
