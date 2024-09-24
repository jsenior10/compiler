#include "token.h"
#include <string>

std::string Token::ToString()
{
	switch (GetTag())
	{
	case NUMBER:
	{
		std::stringstream stream;
		stream << GetNum();
		return stream.str();
	}

	case ID:					 return GetID();
	case BOOL:					 return "bool";
	case TRUE:					 return "true";
	case FALSE:					 return "false";
	case INT:					 return "int";
	case IF:					 return "if";
	case ELSE:					 return "else";
	case RETURN:				 return "return";
	case WHILE:					 return "while";
	case OPERATOR:				 return "operator";
	case SYMBOLPLUS:			 return "+";
	case SYMBOLMINUS:			 return "-";
	case SYMBOLASTERISK:		 return "*";
	case SYMBOLMODULO:			 return "%";
	case SYMBOLSLASH:			 return "/";
	case SYMBOLEQUAL:			 return "==";
	case SYMBOLNOTEQUAL:		 return "!=";
	case SYMBOLLESSTHAN:		 return "<";
	case SYMBOLLESSTHANEQUAL:	 return "<=";
	case SYMBOLGREATERTHAN:		 return ">";
	case SYMBOLGREATERTHANEQUAL: return ">=";
	case SYMBOLAND:				 return "&&";
	case SYMBOLOR:				 return "||";
	case SYMBOLNOT:				 return "!";
	case SYMBOLSEMICOLON:		 return ";";
	case SYMBOLCOMMA:			 return ",";
	case SYMBOLLBRACKET:		 return "(";
	case SYMBOLRBRACKET:		 return ")";
	case SYMBOLLSQUAREBRACKET:	 return "[";
	case SYMBOLRSQUAREBRACKET:	 return "]";
	case SYMBOLLBRACE:			 return "{";
	case SYMBOLRBRACE:			 return "}";
	case SYMBOLCOMMENT:			 return "//";
	case ASSIGN:				 return "=";
	case ENDOFFILE:				 return "<EOF>";
	}

	assert(false && "unknown token encountered");
	return "";
}