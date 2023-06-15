#pragma once

#include "ast-node.h"

namespace stoat
{
struct ExpressionASTNode : public ASTNode
{
    virtual void Accept(ASTVisitor *visitor) const override;

    // for now expressions will only be numeric constants ¯\_(ツ)_/¯
    double m_NumericValue = 0;
};
}