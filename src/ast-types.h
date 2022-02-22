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
    ExpressionASTNode* m_Expression = nullptr;
};

struct CompoundStatementASTNode : public ASTNode
{
    ~CompoundStatementASTNode();
    virtual llvm::Value* CodeGen() override; 

    std::vector<StatementASTNode*> m_Statements;
    StatementASTNode* m_ReturnStatement = nullptr;
};

struct FunctionDefinitionASTNode : public ASTNode
{
    ~FunctionDefinitionASTNode();
    virtual llvm::Value* CodeGen() override; 

    // All functions return doubles for now and we don't need to
    // keep the return type
    std::string m_Identifier;
    CompoundStatementASTNode* m_FunctionBody = nullptr;
};

struct ProgramASTNode : public ASTNode
{
    ~ProgramASTNode();
    virtual llvm::Value* CodeGen() override; 

    // For now a program is a list of function definitions
    std::vector<FunctionDefinitionASTNode*> m_Definitions;
};

}