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
    // TODO: it's wrong, fix it
    for (auto stmt : m_Statements)
    {
        stmt->CodeGen();
    }

    if (m_ReturnStatement)
    {
        return m_ReturnStatement->CodeGen();
    }

    return nullptr;
};
}