#pragma once

#include "scanner.h"
#include "ast-types.h"

namespace stoat
{

class ParserContext
{
public:
    ~ParserContext();

    void SetRoot(ProgramASTNode* root);
    int Parse();

    friend class parser;
    friend class Scanner;

    static ParserContext* GetContext();
    
private:
    ParserContext();

    Scanner m_Scanner;
    Parser m_Parser;
    ProgramASTNode* m_ASTRoot;

    static ParserContext* context;
};

}

