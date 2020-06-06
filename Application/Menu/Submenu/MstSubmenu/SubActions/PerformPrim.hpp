#pragma once

#include <Application/Menu/Actions/BaseSubAction.hpp>
#include <Algorithm/Prim.hpp>
#include <Miscellanous/Timer.hpp>


class PerformPrim : public BaseSubAction
{
    public:
    using PrimResults = std::pair<double, Prim::PathCostAndPath>;

    PerformPrim(const std::string& actionName, std::unique_ptr<Graph>& graphMatrixType,
                                               std::unique_ptr<Graph>& graphListType);
    ~PerformPrim() = default;

    void run();

    private:
    void displayResults(PerformPrim::PrimResults& result, const std::string graphVersion);
    PrimResults runPrimForMatrix();
    PrimResults runPrimForList();

    Prim prim;
    Timer timer;
};
