#include "parser-context.h"

namespace stoat
{
ParserContext* ParserContext::context = nullptr;

ParserContext* ParserContext::GetContext()
{
    if (!context)
        context = new ParserContext();
    
    return context;
}

ASTNode* ParserContext::GetASTRoot()
{
    return m_ASTRoot;
}
void ParserContext::SetASTRoot(ProgramASTNode* root)
{
    m_ASTRoot = root;
}

ParserContext::ParserContext()
    : m_Parser(m_Scanner, *this)

    // Open a new context and module
    , m_LLVMContext(std::make_unique<llvm::LLVMContext>())
    , m_Module(std::make_unique<llvm::Module>("some module", *m_LLVMContext))

    // Create a new builder for the module
    , m_Builder(*m_LLVMContext)
{}
ParserContext::~ParserContext()
{
    if (m_ASTRoot)
        delete m_ASTRoot;
}

int ParserContext::Parse() { return m_Parser.parse(); }

}

