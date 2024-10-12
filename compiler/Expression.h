#pragma once

#include "type.h"
#include "expressionvisitor.h"
#include <iostream>
#include <memory>
#include <vector>

class Expression
{
public:
	explicit Expression (Type type = TYPEUNKNOWN)
		: m_type(type)
	{}

	virtual ~Expression() {}

	Type GetType() const { return m_type; }

	void SetType(Type type) { m_type = type; }

	virtual void* Dispatch(ExpressionVisitor& visitor) = 0;

private:
	Type m_type;
};


using ExpressionPtr = std::unique_ptr<Expression>;

class BoolExpression : public Expression
{
public:
	BoolExpression(bool value)
		: Expression(TYPEBOOL)
		, m_value(value)
	{}

	bool GetValue() const { return m_value; }

	void* Dispatch(ExpressionVisitor& visitor) override { return visitor.Visit(*this); }
private:
	bool m_value;

};

class VariableExpression : public Expression
{
public:
	VariableExpression(const std::string& name)
		: m_name(name)
	{}

	const std::string& GetName() const { return m_name; }

	const VariableDeclaration* GetVarDecl() const { return m_varDecl; }

	void SetVarDecl(const VariableDeclaration* varDecl) { m_varDecl = varDecl; }

	void* Dispatch(ExpressionVisitor& visitor) override { return visitor.Visit(*this); }

private:
	std::string m_name;
	const VariableDeclaration* m_varDecl;
};

class CallExpression : public Expression
{
public:
	CallExpression(const std::string& funcName, std::vector<ExpressionPtr>&& args)
		: m_functionName(funcName)
		, m_args(std::move(args))
		, m_funcDef(nullptr)
	{}
	
	CallExpression(const std::string& funcName, ExpressionPtr exp)
		: m_functionName(funcName)
		, m_args(1)
		, m_funcDef(nullptr)
	{
		m_args[0] = std::move(exp);
	}

	CallExpression(const std::string& funcName, ExpressionPtr leftExp, ExpressionPtr rightExp)
		: m_functionName(funcName)
		, m_args(2)
		, m_funcDef(nullptr)
	{
		m_args[0] = std::move(leftExp);
		m_args[1] = std::move(rightExp);

	}

	const std::string& GetFuncName() const { return m_functionName; }

	const std::vector<ExpressionPtr>& GetArgs() const { return m_args; }

	const FunctionDefinition* GetFuncDef() const { return m_funcDef; }

	void SetFuncDef(const FunctionDefinition* funcDef) { m_funcDef = funcDef; }

	void* Dispatch(ExpressionVisitor& visitor) override { return visitor.Visit(*this); }

private:
	std::string m_functionName;
	std::vector<ExpressionPtr> m_args;
	const FunctionDefinition* m_funcDef;
};

using CallExpressionPtr = std::unique_ptr<CallExpression>;