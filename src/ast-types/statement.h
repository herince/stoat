#pragma once

#include "ast-node.h"
#include "expression.h"

namespace stoat
{
struct StatementASTNode : public ASTNode
{
    ~StatementASTNode();

    virtual void Accept(ASTVisitor *visitor) const override;

    // We only have expression statements for now
    ExpressionASTNode* m_Expression = nullptr;
};
}