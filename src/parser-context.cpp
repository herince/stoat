#include "parser-context.h"

namespace stoat
{
ParserContext::ParserContext() : m_Parser(m_Scanner, *this) {}
ParserContext::~ParserContext() {}

int ParserContext::parse() { return m_Parser.parse(); }

}

