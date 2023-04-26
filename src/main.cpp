#include "parser-context.h"
#include "llvm/Support/raw_os_ostream.h"

int main()
{
    auto ctx = stoat::ParserContext::GetContext();
    if (ctx)
    {
        ctx->Parse();
        ctx->GetASTRoot()->CodeGen();

        std::error_code ec;
        llvm::raw_fd_ostream rfdo("out/test.ll", ec);
        // check ec ??
        ctx->m_Module->print(rfdo, nullptr);
    }
    else
    {
        std::cerr << "No context. RIP ;-;";
    }

    stoat::ParserContext::FreeContext();

    return 0;
}