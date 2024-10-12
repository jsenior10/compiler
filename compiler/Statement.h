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