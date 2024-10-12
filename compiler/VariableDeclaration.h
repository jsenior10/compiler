#pragma once

#include "type.h"
#include <cassert>
#include <iostream>
#include <memory>
#include <string>

class VariableDeclaration
{
public:
	enum Kind
	{
		LOCAL,
		PARAM
	};


	VariableDeclaration(Kind kind, Type type, const std::string& name)
		: m_kind(kind)
		, m_type(type)
		, m_name(name)
	{}

	Kind GetKind() const { return m_kind; }

	const Type& GetType() const { return m_type; }

	const std::string& GetName() const { return m_name; }

private:
	Type m_type;
	std::string m_name;
	Kind m_kind;
};

using VariableDeclarationPtr = std::unique_ptr<VariableDeclaration>;

inline std::ostream& operator<<(std::ostream& out, const VariableDeclaration& varDecl)
{
	return out << ToString(varDecl.GetType()) << ' ' << varDecl.GetName();
}