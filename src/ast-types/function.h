#pragma once

#include "ast-node.h"
#include "compound-statement.h"

namespace stoat
{
struct FunctionDefinitionASTNode : public ASTNode
{
    ~FunctionDefinitionASTNode();

    virtual llvm::Value* CodeGen() override; 

    // All functions return doubles for now and we don't need to
    // keep the return type
    std::string m_Identifier;
    CompoundStatementASTNode* m_FunctionBody = nullptr;
};
}