#pragma once

#include <iostream>
#include <vector>

struct ASTNode
{
    virtual ~ASTNode() {}

    // LLVM IR
    virtual void CodeGen() {}; // = 0;

    // Print in .dot format and use graphviz to visualize the AST
    virtual void PrintNode(std::ostream& o) {}; // = 0;
};

struct ExpressionASTNode : public ASTNode {
    // for now expressions will only be numeric constants ¯\_(ツ)_/¯
    double m_NumericValue = 0;
};

struct StatementASTNode : public ASTNode
{
    ~StatementASTNode()
    {
        delete m_Expression;
    }
    // We only have expression statements for now
    ExpressionASTNode* m_Expression;
};

struct ProgramASTNode : public ASTNode
{
    ~ProgramASTNode()
    {
        for (auto stmt : m_Statements)
        {
            delete stmt;
        }
    }

    // For now a program will be what seems to be the definition
    // of compound statement in the grammar
    std::vector<StatementASTNode*> m_Statements;
};
