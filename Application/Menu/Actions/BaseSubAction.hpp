#pragma once

#include <string>
#include <memory>
#include <Application/Menu/Actions/BaseAction.hpp>
#include <Graph/GraphMatrix.hpp>
#include <Graph/GraphList.hpp>


// Abstract SubAction class for polymorphic needs


class BaseSubAction : public BaseAction
{
    public:
    BaseSubAction(const std::string& actionName, std::unique_ptr<GraphMatrix>& graphMatrixType,
                                                 std::unique_ptr<GraphList>& graphListType);
    virtual ~BaseSubAction() = default;

    virtual void run() = 0;


    protected:
    std::string name;
    std::unique_ptr<GraphMatrix>& graphMatrix;
    std::unique_ptr<GraphList>& graphList;
};
