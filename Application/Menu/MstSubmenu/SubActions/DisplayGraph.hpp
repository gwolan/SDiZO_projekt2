#pragma once

#include <Application/Menu/Actions/BaseSubAction.hpp>


class DisplayGraph : public BaseSubAction
{
    public:
    DisplayGraph(const std::string& actionName, std::unique_ptr<GraphMatrix>& graphMatrixType,
                                                std::unique_ptr<GraphList>& graphListType);
    ~DisplayGraph() = default;

    void run();
};