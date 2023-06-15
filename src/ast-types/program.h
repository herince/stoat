#pragma once

#include <vector>
#include "ast-node.h"

namespace stoat
{
class FunctionDefinitionASTNode;

struct ProgramASTNode : public ASTNode
{
    ~ProgramASTNode();

    virtual void Accept(ASTVisitor *visitor) const override;

    // For now a program is a list of function definitions
    std::vector<FunctionDefinitionASTNode*> m_Definitions;
};
}