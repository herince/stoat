#pragma once

#include "scanner.h"

namespace stoat
{

class ParserContext
{
public:
    ParserContext();
    ~ParserContext();

    int parse();

    friend class parser;
    friend class Scanner;
    
private:
    Scanner m_Scanner;
    Parser m_Parser;
};

}

