#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <sstream>
#include <cassert>

enum Tokens {
	NUMBER,
	ID,

	// keywords
	BOOL,
	TRUE,
	FALSE,
	INT,
	IF,
	ELSE,
	RETURN,
	WHILE,
	OPERATOR,

	// operators
	SYMBOLPLUS,
	SYMBOLMINUS,
	SYMBOLASTERISK,
	SYMBOLMODULO,
	SYMBOLSLASH,
	SYMBOLEQUAL,
	SYMBOLNOTEQUAL,
	SYMBOLLESSTHAN,
	SYMBOLLESSTHANEQUAL,
	SYMBOLGREATERTHAN,
	SYMBOLGREATERTHANEQUAL,
	SYMBOLAND,
	SYMBOLOR,
	SYMBOLNOT,

	// punctuation
	SYMBOLSEMICOLON,
	SYMBOLCOMMA,
	SYMBOLLBRACKET,
	SYMBOLRBRACKET,
	SYMBOLLSQUAREBRACKET,
	SYMBOLRSQUAREBRACKET,
	SYMBOLLBRACE,
	SYMBOLRBRACE,
	SYMBOLCOMMENT,
	ASSIGN,
	ENDOFFILE
};

class Token {
public:
	Token(int value)
		: m_tag(ID)
		, m_int(value)
	{}

	Token(const std::string& id)
		: m_tag(ID)
		, m_id(id)
	{}

	Token(Tokens tag)
		: m_tag(tag)
	{ 
		assert(tag != INT && tag != ID && "values needed for ID and INT tokens");
	}

	Tokens GetTag() { return m_tag; }

	int GetNum()
	{
		assert(GetTag() == NUMBER && "NUMBER token expected");
		return m_int;
	}

	std::string& GetID()
	{
		assert(GetTag() == ID && "ID token expected");
		return m_id;
	}

	std::string ToString();

	bool operator==(Token& other)
	{
		if (GetTag() != other.GetTag())
			return false;

		if (GetTag() == NUMBER)
			return GetNum() == other.GetNum();

		if (GetTag() == ID)
			return GetID() == other.GetID();

		return true;
	}

	bool operator!=(Token& other) { return !(*this == other); }

	// quick check to see if token can be preceded by an operator
	bool isOperator()
	{
		switch (GetTag())
		{
			case SYMBOLPLUS:
			case SYMBOLMINUS:
			case SYMBOLASTERISK:
			case SYMBOLSLASH:
			case SYMBOLMODULO:
			case SYMBOLEQUAL:
			case SYMBOLNOTEQUAL:
			case SYMBOLLESSTHAN:
			case SYMBOLLESSTHANEQUAL:
			case SYMBOLGREATERTHAN:
			case SYMBOLGREATERTHANEQUAL:
			case SYMBOLAND:
			case SYMBOLOR:
			case SYMBOLNOT:
			case BOOL:
			case INT:
				return true;

			default:
				return false;
		}
	}

private:
	Tokens m_tag;
	int m_int; // integer value if token is DIGIT
	std::string m_id; // identifier value if token is ID
};

#endif