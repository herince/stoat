#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Type.h"

#include "statement.h"

namespace stoat
{
StatementASTNode::~StatementASTNode()
{
    delete m_Expression;
}
void StatementASTNode::Accept(ASTVisitor *visitor) const
{
    visitor->VisitStatement(this);
}
}