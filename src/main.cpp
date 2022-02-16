#include "parser-context.h"

int main()
{
    auto ctx = stoat::ParserContext::GetContext();
    if (ctx)
    {
        ctx->Parse();
        std::cout << "Yey!";

        delete ctx;
    }
    else
    {
        std::cerr << "No context. RIP ;-;";
    }

    return 0;
}