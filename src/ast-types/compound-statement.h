#pragma once

#include <vector>

#include "ast-node.h"
#include "statement.h"

namespace stoat
{
struct CompoundStatementASTNode : public ASTNode
{
    ~CompoundStatementASTNode();

    virtual llvm::Value* CodeGen() override; 

    std::vector<StatementASTNode*> m_Statements;
    StatementASTNode* m_ReturnStatement = nullptr;
};
}