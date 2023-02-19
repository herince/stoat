#include <iostream>
#include <vector>

#include "ast-node.h"
#include "../parser-context.h"

namespace stoat
{
ASTNode::~ASTNode() {}
void ASTNode::PrintError(const char* errorMessage)
{
    fprintf(stderr, errorMessage);
}
void ASTNode::PrintNode(std::ostream& o) {}

ProgramASTNode::~ProgramASTNode()
{
    for (auto def : m_Definitions)
    {
        delete def;
    }
}
}