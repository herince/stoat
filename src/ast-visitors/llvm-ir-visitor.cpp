#include "llvm-ir-visitor.h"

#include "llvm/IR/Type.h"
#include "llvm/IR/DerivedTypes.h"

#include "../ast-types/ast-node.h"
#include "../ast-types/expression.h"
#include "../ast-types/statement.h"
#include "../ast-types/compound-statement.h"
#include "../ast-types/function.h"
#include "../ast-types/program.h"
#include "../parser-context.h"

namespace stoat {

void LLVMIRVisitor::VisitProgram(const ProgramASTNode* node)
{
    for (int i = node->m_Definitions.size() - 1; i >= 0; --i)
    {
        node->m_Definitions[i]->Accept(this);
    }
}

void LLVMIRVisitor::VisitFunction(const FunctionDefinitionASTNode* node)
{
    using namespace llvm;

    auto parserContext = ParserContext::GetContext();
    auto& llvmContext = parserContext->m_LLVMContext;
    auto& llvmModule = parserContext->m_Module;
    auto& llvmBuilder = parserContext->m_Builder;
    Function* function = llvmModule->getFunction(node->m_Identifier);

    if (function)
    {
        // TODO: Better message, name of func, etc.
        // node->PrintError("Trying to redefine an existing function! :(");
        m_ReturnValue = nullptr;
        return;
    }

    std::vector<Type*> args;
    auto functionType = FunctionType::get(
        Type::getDoubleTy(*llvmContext), args, false);
    function = Function::Create(
        functionType,
        Function::ExternalLinkage,
        node->m_Identifier,
        llvmModule.get());

    BasicBlock* block = BasicBlock::Create(
        *llvmContext,
        node->m_Identifier.c_str(),
        function);
    llvm::IRBuilder<> funcBuilder(block);

    // parserContext->m_NamedValues.clear();
    // for (auto& arg : function->args())
    // {
    //     parserContext->m_NamedValues[std::string(arg.getName())] = &arg;
    // }

    if (node->m_FunctionBody)
    {
        node->m_FunctionBody->Accept(this);
        if (m_ReturnValue) {
            funcBuilder.CreateRet(m_ReturnValue);
            m_ReturnValue = function;
            return;
        }
    }

    // Verify that typed functions always return, otherwise:
    function->eraseFromParent();
    m_ReturnValue = nullptr;
}

void LLVMIRVisitor::VisitCompoundStatement(const CompoundStatementASTNode* node)
{
    for (int i = node->m_Statements.size() - 1; i >= 0; --i)
    {
        node->m_Statements[i]->Accept(this);
    }

    if (node->m_ReturnStatement)
    {
        node->m_ReturnStatement->Accept(this);
    }
}

void LLVMIRVisitor::VisitStatement(const StatementASTNode* node)
{
    if (node->m_Expression)
    {
        node->m_Expression->Accept(this);
    }
}

void LLVMIRVisitor::VisitExpression(const ExpressionASTNode* node)
{
    using namespace llvm;

    auto parserContext = ParserContext::GetContext();
    auto& llvmContext = parserContext->m_LLVMContext;
    m_ReturnValue = ConstantFP::get(*llvmContext, APFloat(node->m_NumericValue));
}

}