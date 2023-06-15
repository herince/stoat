#pragma once

#include <vector>

#include "ast-node.h"
#include "statement.h"

namespace stoat
{
struct CompoundStatementASTNode : public ASTNode
{
    ~CompoundStatementASTNode();

    virtual void Accept(ASTVisitor *visitor) const override;

    std::vector<StatementASTNode*> m_Statements;
    StatementASTNode* m_ReturnStatement = nullptr;
};
}