#pragma once

#include "ast-node.h"
#include "expression.h"

namespace stoat
{
struct StatementASTNode : public ASTNode
{
    ~StatementASTNode();

    virtual llvm::Value* CodeGen() override; 

    // We only have expression statements for now
    ExpressionASTNode* m_Expression = nullptr;
};
}