#pragma once

#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Type.h"

#include <iostream>
#include <vector>

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

struct ExpressionASTNode : public ASTNode
{
    virtual llvm::Value* CodeGen() override; 

    // for now expressions will only be numeric constants ¯\_(ツ)_/¯
    double m_NumericValue = 0;
};

struct StatementASTNode : public ASTNode
{
    ~StatementASTNode();
    virtual llvm::Value* CodeGen() override; 

    // We only have expression statements for now
    ExpressionASTNode* m_Expression;
};

struct ProgramASTNode : public ASTNode
{
    ~ProgramASTNode();
    virtual llvm::Value* CodeGen() override; 

    // For now a program will be what seems to be the definition
    // of compound statement in the grammar
    std::vector<StatementASTNode*> m_Statements;
};

}