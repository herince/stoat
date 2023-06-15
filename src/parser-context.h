#pragma once


#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"

#include "scanner.h"
#include "ast-types/program.h"

namespace stoat
{

class ParserContext
{
public:
    ~ParserContext();

    ProgramASTNode* GetASTRoot();
    void SetASTRoot(ProgramASTNode* root);
    int Parse();

    friend class parser;
    friend class Scanner;

    static ParserContext* GetContext();
    static void FreeContext();

    // todo: should these be here?
    llvm::IRBuilder<> m_Builder;
    std::unique_ptr<llvm::LLVMContext> m_LLVMContext;
    std::unique_ptr<llvm::Module> m_Module;
    std::map<std::string, llvm::Value*> m_NamedValues;

private:
    ParserContext();

    Scanner m_Scanner;
    Parser m_Parser;
    ProgramASTNode* m_ASTRoot;

    static ParserContext* Context;
};

}

