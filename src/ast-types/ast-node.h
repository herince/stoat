#pragma once

#include "../ast-visitors/ast-visitor.h"

namespace stoat
{
struct ASTNode
{
    virtual ~ASTNode();

    virtual void Accept(ASTVisitor *visitor) const = 0;

    void PrintError(const char* errorMessage);

    // Print in .dot format and use graphviz to visualize the AST
    // virtual void PrintNode(std::ostream& o); // = 0;
};
}