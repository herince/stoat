#pragma once

namespace stoat
{
struct ProgramASTNode;
struct FunctionDefinitionASTNode;
struct CompoundStatementASTNode;
struct StatementASTNode;
struct ExpressionASTNode;

struct ASTVisitor
{
    virtual void VisitProgram(const ProgramASTNode*) = 0;
    virtual void VisitFunction(const FunctionDefinitionASTNode*) = 0;
    virtual void VisitCompoundStatement(const CompoundStatementASTNode*) = 0;
    virtual void VisitStatement(const StatementASTNode*) = 0;
    virtual void VisitExpression(const ExpressionASTNode*) = 0;
};
}