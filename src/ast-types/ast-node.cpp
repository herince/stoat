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
}