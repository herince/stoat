#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Type.h"

#include "../parser-context.h"
#include "expression.h"

namespace stoat
{
void ExpressionASTNode::Accept(ASTVisitor *visitor) const
{
    visitor->VisitExpression(this);
}
}