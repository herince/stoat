#pragma once


#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"

#include "scanner.h"
#include "ast-types.h"

namespace stoat
{

class ParserContext
{
public:
    ~ParserContext();

    ASTNode* GetASTRoot();
    void SetASTRoot(ProgramASTNode* root);
    int Parse();

    friend class parser;
    friend class Scanner;

    static ParserContext* GetContext();
    
    // TODO: hide
    llvm::LLVMContext m_LLVMContext;
    // llvm::IRBuilder<> m_Builder;
    std::unique_ptr<llvm::Module> m_Module;

    // Not sure if this should be here ??
    std::map<std::string, llvm::Value*> m_NamedValues;

private:
    ParserContext();

    Scanner m_Scanner;
    Parser m_Parser;
    ProgramASTNode* m_ASTRoot;

    static ParserContext* context;
};

}

