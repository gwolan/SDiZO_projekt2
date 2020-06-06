#pragma once

#include <Application/Menu/Actions/BaseSubAction.hpp>
#include <Algorithm/PrimMatrix.hpp>
#include <Miscellanous/Timer.hpp>


class PerformPrim : public BaseSubAction
{
    public:
    PerformPrim(const std::string& actionName, std::unique_ptr<GraphMatrix>& graphMatrixType,
                                              std::unique_ptr<GraphList>& graphListType);
    ~PerformPrim() = default;

    void run();

    private:
    void displayResults(PrimMatrix::PathCostAndPath& result);

    PrimMatrix primMatrix;
    Timer timer;
};
