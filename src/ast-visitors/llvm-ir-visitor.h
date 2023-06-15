#pragma once

#include "ast-visitor.h"

namespace llvm
{
class Value;
}

namespace stoat
{
struct LLVMIRVisitor : public ASTVisitor
{
    virtual void VisitProgram(const ProgramASTNode*) override;
    virtual void VisitFunction(const FunctionDefinitionASTNode*) override;
    virtual void VisitCompoundStatement(const CompoundStatementASTNode*) override;
    virtual void VisitStatement(const StatementASTNode*) override;
    virtual void VisitExpression(const ExpressionASTNode*) override;

    llvm::Value* m_ReturnValue = nullptr;
};
}