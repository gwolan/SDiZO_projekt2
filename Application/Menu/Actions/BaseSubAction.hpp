#pragma once

#include <Application/Menu/Actions/BaseAction.hpp>
#include <Graph/Graph.hpp>


// Abstract SubAction class for polymorphic needs


class BaseSubAction : public BaseAction
{
    public:
    BaseSubAction(const std::string& actionName, std::unique_ptr<Graph>& graphMatrixType,
                                                 std::unique_ptr<Graph>& graphListType);
    virtual ~BaseSubAction() = default;

    virtual void run() = 0;


    protected:
    std::string name;
    std::unique_ptr<Graph>& graphMatrix;
    std::unique_ptr<Graph>& graphList;
};
