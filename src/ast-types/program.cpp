#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Type.h"

#include "program.h"
#include "function.h"

namespace stoat
{
llvm::Value* ProgramASTNode::CodeGen()
{
    for (auto def : m_Definitions)
    {
        auto value = def->CodeGen();
        if (value)
        {
            // value->print(llvm::errs());
            printf("\n");
        }
    }
    return nullptr;
};
}