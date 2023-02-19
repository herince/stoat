#pragma once

#include "ast-node.h"

namespace stoat
{
struct ExpressionASTNode : public ASTNode
{
    virtual llvm::Value* CodeGen() override; 

    // for now expressions will only be numeric constants ¯\_(ツ)_/¯
    double m_NumericValue = 0;
};
}