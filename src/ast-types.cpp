#include "ast-types.h"
#include "parser-context.h"

#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Type.h"

#include <iostream>
#include <vector>

namespace stoat
{
ASTNode::~ASTNode() {}
void ASTNode::PrintError(const char* errorMessage)
{
    fprintf(stderr, errorMessage);
}
void ASTNode::PrintNode(std::ostream& o) {}

llvm::Value* ExpressionASTNode::CodeGen()
{
    auto parserContext = ParserContext::GetContext();
    auto& llvmContext = parserContext->m_LLVMContext;
    return llvm::ConstantFP::get(llvmContext, llvm::APFloat(m_NumericValue));
};

StatementASTNode::~StatementASTNode()
{
    delete m_Expression;
}
llvm::Value* StatementASTNode::CodeGen()
{
    if (m_Expression)
    {
        auto value = m_Expression->CodeGen();

        if (value)
        {
            value->print(llvm::errs());
            printf("\n");
        }
    }
    return nullptr;
};

CompoundStatementASTNode::~CompoundStatementASTNode()
{
    for (auto stmt : m_Statements)
    {
        delete stmt;
    }
}
llvm::Value* CompoundStatementASTNode::CodeGen()
{
    for (auto stmt : m_Statements)
    {
        stmt->CodeGen();
    }
    return nullptr;
};

FunctionDefinitionASTNode::~FunctionDefinitionASTNode()
{
    delete m_FunctionBody;
}
llvm::Value* FunctionDefinitionASTNode::CodeGen()
{
    m_FunctionBody->CodeGen();
    return nullptr;
};

ProgramASTNode::~ProgramASTNode()
{
    for (auto def : m_Definitions)
    {
        delete def;
    }
}
llvm::Value* ProgramASTNode::CodeGen()
{
    for (auto def : m_Definitions)
    {
        def->CodeGen();
    }
    return nullptr;
};

}