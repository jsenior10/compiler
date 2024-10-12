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