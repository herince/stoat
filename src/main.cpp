#include "parser-context.h"
#include "ast-visitors/llvm-ir-visitor.h"
#include "llvm/Support/raw_os_ostream.h"

int main()
{
    auto ctx = stoat::ParserContext::GetContext();
    if (ctx)
    {
        ctx->Parse();

        auto v = new stoat::LLVMIRVisitor();
        v->VisitProgram(ctx->GetASTRoot());

        std::error_code ec;
        llvm::raw_fd_ostream rfdo("out/test.ll", ec);
        // check ec ??

        ctx->m_Module->print(rfdo, nullptr);

        delete v;
    }
    else
    {
        std::cerr << "No context. RIP ;-;";
    }

    stoat::ParserContext::FreeContext();

    return 0;
}