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

llvm::Value* ProgramASTNode::CodeGen()
{
    for (auto def : m_Definitions)
    {
        auto value = def->CodeGen();
        if (value)
        {
            // value->print(llvm::errs());
        }
    }
    return nullptr;
};
}