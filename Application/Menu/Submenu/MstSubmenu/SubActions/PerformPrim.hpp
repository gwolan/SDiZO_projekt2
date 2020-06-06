#pragma once

#include <Application/Menu/Actions/BaseSubAction.hpp>
#include <Algorithm/Prim.hpp>
#include <Miscellanous/Timer.hpp>


class PerformPrim : public BaseSubAction
{
    public:
    PerformPrim(const std::string& actionName, std::unique_ptr<Graph>& graphMatrixType,
                                               std::unique_ptr<Graph>& graphListType);
    ~PerformPrim() = default;

    void run();

    private:
    void displayResults(Prim::PathCostAndPath& result);

    Prim primMatrix;
    Timer timer;
};
