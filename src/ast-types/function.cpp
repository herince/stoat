#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Type.h"

#include "../parser-context.h"
#include "function.h"

namespace stoat
{
FunctionDefinitionASTNode::~FunctionDefinitionASTNode()
{
    delete m_FunctionBody;
}
llvm::Value* FunctionDefinitionASTNode::CodeGen()
{
    using namespace llvm;

    auto parserContext = ParserContext::GetContext();
    auto& llvmContext = parserContext->m_LLVMContext;
    auto& llvmModule = parserContext->m_Module;
    auto& llvmBuilder = parserContext->m_Builder;
    Function* function = llvmModule->getFunction(m_Identifier);

    if (function)
    {
        // TODO: Better message, name of func, etc.
        PrintError("Trying to redefine an existing function! :(");
        return nullptr;
    }

    std::vector<Type*> args;
    auto functionType = FunctionType::get(
        Type::getDoubleTy(*llvmContext), args, false);
    function = Function::Create(
        functionType,
        Function::ExternalLinkage,
        m_Identifier,
        llvmModule.get());

    BasicBlock* block = BasicBlock::Create(
        *llvmContext,
        m_Identifier.c_str(),
        function);
    llvm::IRBuilder<> funcBuilder(block);

    // parserContext->m_NamedValues.clear();
    // for (auto& arg : function->args())
    // {
    //     parserContext->m_NamedValues[std::string(arg.getName())] = &arg;
    // }

    if (m_FunctionBody)
    {
        if (auto returnValue = m_FunctionBody->CodeGen()) {
            funcBuilder.CreateRet(returnValue);
            return function;
        }
    }

    // Verify that typed functions always return, otherwise:
    // f->eraseFromParent();
    return nullptr;  
};
}