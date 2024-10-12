#pragma once

#include "syntax.h"

class ExpressionVisitor
{
public:
	virtual void* Visit(BoolExpression& expression) = 0;
	virtual void* Visit(IntExpression& expression) = 0;
	virtual void* Visit(VariableExpression& expression) = 0;
	virtual void* Visit(CallExpression& expression) = 0;
};

class StatementVisitor
{
public:
	virtual void* Visit(CallStatement& expression) = 0;
	virtual void* Visit(AssignStatement& expression) = 0;
	virtual void* Visit(ReturnStatement& expression) = 0;
	virtual void* Visit(IfStatement& expression) = 0;
	virtual void* Visit(WhileStatement& expression) = 0;
	virtual void* Visit(DeclarationStatement& expression) = 0;
	virtual void* Visit(SequenceStatement& expression) = 0;
};