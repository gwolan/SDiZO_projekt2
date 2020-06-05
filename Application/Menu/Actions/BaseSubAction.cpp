#include <Application/Menu/Actions/BaseSubAction.hpp>


BaseSubAction::BaseSubAction(const std::string& actionName, std::unique_ptr<GraphMatrix>& graphMatrixType,
                                                            std::unique_ptr<GraphList>& graphListType)
    : BaseAction(actionName)
    , graphMatrix(graphMatrixType)
    , graphList(graphListType)
{ }
