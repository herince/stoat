#include "parser-context.h"

// namespace stoat {
//     Parser::symbol_type getNextToken(Scanner* scanner)
//     {
//         return scanner->get_next_token();
//     }
// }

int main()
{
    stoat::ParserContext ctx;
    ctx.parse();
    return 0;
}