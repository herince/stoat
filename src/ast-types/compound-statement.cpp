#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Type.h"

#include "compound-statement.h"

namespace stoat
{
CompoundStatementASTNode::~CompoundStatementASTNode()
{
    for (auto stmt : m_Statements)
    {
        delete stmt;
    }

    delete m_ReturnStatement;
}

void CompoundStatementASTNode::Accept(ASTVisitor *visitor) const
{
    visitor->VisitCompoundStatement(this);
}
}