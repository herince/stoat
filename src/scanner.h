#pragma once

#if !defined(yyFlexLexerOnce)
#undef yyFlexLexer
#define yyFlexLexer stoat_FlexLexer
#include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL stoat::Parser::symbol_type stoat::Scanner::get_next_token()

#include "generated/c-parser-generated.hpp"

namespace stoat
{

class ParserContext;

class Scanner : public yyFlexLexer
{
public:
    virtual Parser::symbol_type get_next_token();
};

}
