#pragma once

#include <cassert>

enum Type
{
	TYPEUNKNOWN,
	TYPEBOOL,
	TYPEINT
};

const char* ToString(Type type)
{
	switch (type)
	{
	case TYPEUNKNOWN:
		return "<unknown>";
	case TYPEBOOL:
		return "bool";
	case TYPEINT:
		return "int";
	}

	assert(false && "unknown type");
	return "";
}