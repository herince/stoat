#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Type.h"

#include "program.h"
#include "function.h"

namespace stoat
{
ProgramASTNode::~ProgramASTNode()
{
    for (auto def : m_Definitions)
    {
        delete def;
    }
}

void ProgramASTNode::Accept(ASTVisitor *visitor) const
{
    visitor->VisitProgram(this);
}
}