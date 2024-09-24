#pragma once

#include <memory>

class Expression;
class BoolExpression;
class IntExpression;
class CallExpression;
class VariableExpression;

class Statement;
class AssignStatement;
class CallStatement;
class IfStatement;
class ReturnStatement;
class WhileStatement;

class FunctionDefinition;
class Program;
class VariableDeclaration;

using ExpressionPtr = std::unique_ptr<Expression>;
using CallExpressionPtr = std::unique_ptr<CallExpression>;
using FunctionDefinitionPtr = std::unique_ptr<FunctionDefinition>;
using ProgramPtr = std::unique_ptr<Program>;
using StatementPtr = std::unique_ptr<Statement>;
using VariableDeclarationPtr = std::unique_ptr<VariableDeclaration>;