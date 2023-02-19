#pragma once

#include "llvm/IR/Type.h"
#include "llvm/IR/DerivedTypes.h"

namespace stoat
{
struct ASTNode
{
    virtual ~ASTNode();

    // LLVM IR
    virtual llvm::Value* CodeGen() = 0;
    void PrintError(const char* errorMessage);

    // Print in .dot format and use graphviz to visualize the AST
    virtual void PrintNode(std::ostream& o); // = 0;
};
}