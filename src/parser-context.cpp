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

ParserContext::ParserContext() : m_Parser(m_Scanner, *this) {}
ParserContext::~ParserContext()
{
    if (m_ASTRoot)
        delete m_ASTRoot;
}

int ParserContext::Parse() { return m_Parser.parse(); }

}

