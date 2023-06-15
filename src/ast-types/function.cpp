#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Type.h"

#include "../parser-context.h"
#include "function.h"

namespace stoat
{
FunctionDefinitionASTNode::~FunctionDefinitionASTNode()
{
    delete m_FunctionBody;
}

void FunctionDefinitionASTNode::Accept(ASTVisitor *visitor) const
{
    visitor->VisitFunction(this);
}
}