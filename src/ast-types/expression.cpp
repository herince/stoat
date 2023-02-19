#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Type.h"

#include "../parser-context.h"
#include "expression.h"

namespace stoat
{
llvm::Value* ExpressionASTNode::CodeGen()
{
    auto parserContext = ParserContext::GetContext();
    auto& llvmContext = parserContext->m_LLVMContext;
    return llvm::ConstantFP::get(*llvmContext, llvm::APFloat(m_NumericValue));
};
}