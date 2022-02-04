%{
#include "../scanner.h"
%}

%option noyywrap
%option c++
%option yyclass="Scanner"
%option prefix="stoat_"

ID [a-zA-Z][0-9a-zA-Z]*
NUMBER [+-]?[1-9][0-9]*(.[0-9]+)?
WHITESPACE [ \t\n]+

%%

"(" { return stoat::Parser::make_LEFT_PAREN(); }
")" { return stoat::Parser::make_RIGHT_PAREN(); }
";" { return stoat::Parser::make_SEMICOLON(); }

"double" { return stoat::Parser::make_DOUBLE(); }

{ID} {
    return stoat::Parser::make_IDENTIFIER(yytext);
}
{NUMBER} {
    printf(">>>>>>>>>>>>>>>>>>>>%s\n", yytext);
    printf(">>>>>>>>>>>>>>>>>>>> as double - %.2f\n", std::stod(yytext));

    return stoat::Parser::make_NUMBER(std::stod(yytext));
}

{WHITESPACE} {}

%%
