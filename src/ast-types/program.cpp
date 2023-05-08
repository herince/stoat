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
    for (int i = m_Definitions.size() - 1; i >= 0; --i)
    {
        m_Definitions[i]->CodeGen();
    }
    return nullptr;
};
}