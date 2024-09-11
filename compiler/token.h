#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <sstream>

enum Tokens {
	NONTOKEN,
	LETTER,
	DIGIT,
	SYMBOLPLUS,
	SYMBOLMINUS,
	SYMBOLASTERISK,
	SYMBOLSLASH,
	SYMBOLCOMPARISON,
	SYMBOLEQUAL,
	SYMBOLSEMICOLON,
	SYMBOLCOMMA,
	SYMBOLBRACKET,
	SYMBOLSQUAREBRACKET,
	SYMBOLBRACE,
	SYMBOLCOMMENT,
	KEYWORDS,
	READ,
	WRITE
};

struct Token {
	Tokens type;
	int value;
	int line;
	std::string str;
};

#endif