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
llvm::Value* StatementASTNode::CodeGen()
{
    if (m_Expression)
    {
        auto value = m_Expression->CodeGen();
        if (value)
        {
            // value->print(llvm::errs());
            return value;
        }
    }

    return nullptr;
};
}