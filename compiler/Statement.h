#pragma once

#include "Expression.h"
#include "VariableDeclaration.h"

class Statement
{
public:
	virtual ~Statement() {}

	virtual void Dispatch(StatementVisitor& visitor) = 0;

private:


};

using StatementPtr = std::unique_ptr<Statement>;

class CallStatement : public Statement
{
public:
	CallStatement(CallExpressionPtr&& callExp)
		: m_callExp(std::move(callExp))
	{}
	
	const CallExpression& GetCallExpression() const { return *m_callExp; }

	void Dispatch(StatementVisitor& visitor) override { visitor.Visit(*this); }

private:
	CallExpressionPtr m_callExp;
};

class AssignStatement : public Statement
{
public:
	AssignStatement(const std::string& varName, ExpressionPtr&& rval)
		: m_varName(varName)
		, m_rval(std::move(rval))
	{}

	const std::string& GetVarName() const { return m_varName; }

	const Expression& getRval() const { return *m_rval; }

	const VariableDeclaration* GetVarDecl() const { return m_varDecl; }

	void SetVarDecl(const VariableDeclaration* varDecl) { m_varDecl = varDecl; }

	void Dispatch(StatementVisitor& visitor) override { visitor.Visit(*this); }

private:
	std::string m_varName;
	ExpressionPtr m_rval;
	const VariableDeclaration* m_varDecl;
};