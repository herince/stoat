#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Type.h"

#include "../parser-context.h"
#include "expression.h"

namespace stoat
{
llvm::Value* ExpressionASTNode::CodeGen()
{
    using namespace llvm;

    auto parserContext = ParserContext::GetContext();
    auto& llvmContext = parserContext->m_LLVMContext;
    return ConstantFP::get(*llvmContext, APFloat(m_NumericValue));
};
}