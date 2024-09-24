#pragma once

#include "lexer.h"

class TokenStream
{
public:
	TokenStream(const char* source)
		:m_source(source)
		, m_token(ENDOFFILE)
	{
		++*this;
	}

	TokenStream& operator++()
	{
		m_token = Lexer(m_source);
		return *this;
	}

	TokenStream& operator++()
	{
		TokenStream before(*this);
		this->operator*();
		return before;
	}

	Token operator*() { return m_token; }

private:
	const char* m_source;
	Token m_token;
};