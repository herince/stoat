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
llvm::Value* CompoundStatementASTNode::CodeGen()
{
    for (int i = m_Statements.size() - 1; i >= 0; --i)
    {
        m_Statements[i]->CodeGen();
    }

    if (m_ReturnStatement)
    {
        return m_ReturnStatement->CodeGen();
    }

    return nullptr;
};
}