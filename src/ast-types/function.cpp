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
    auto parserContext = ParserContext::GetContext();
    auto& llvmContext = parserContext->m_LLVMContext;
    auto& llvmModule = parserContext->m_Module;
    auto& llvmBuilder = parserContext->m_Builder;
    llvm::Function* function = llvmModule->getFunction(m_Identifier);

    if (function)
    {
        // TODO: Better message, name of func, etc.
        PrintError("Trying to redefine an existing function! :(");
        return nullptr;
    }

    std::vector<llvm::Type*> args;
    auto functionType = llvm::FunctionType::get(
        llvm::Type::getDoubleTy(*llvmContext), args, false);
    function = llvm::Function::Create(
        functionType,
        llvm::Function::ExternalLinkage,
        m_Identifier,
        llvmModule.get());

    const auto blockName = llvm::Twine(m_Identifier.c_str());
    llvm::BasicBlock* block = llvm::BasicBlock::Create(
        *llvmContext,
        blockName,
        function);
    llvmBuilder.SetInsertPoint(block);

    if (m_FunctionBody)
    {
        if (auto returnValue = m_FunctionBody->CodeGen()) {
            llvmBuilder.CreateRet(returnValue);
        }
    }

    return function;
};
}