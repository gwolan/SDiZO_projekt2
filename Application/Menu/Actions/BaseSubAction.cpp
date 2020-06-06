#include <Application/Menu/Actions/BaseSubAction.hpp>


BaseSubAction::BaseSubAction(const std::string& actionName, std::unique_ptr<Graph>& graphMatrixType,
                                                            std::unique_ptr<Graph>& graphListType)
    : BaseAction(actionName)
    , graphMatrix(graphMatrixType)
    , graphList(graphListType)
{ }
