#include "BinaryOpNode.h"
#include <string.h>

BinaryOpNode::BinaryOpNode(std::string o, AstNode* n1, AstNode* n2) : _operand(o), _num1(n1), _num2(n2) {}

double BinaryOpNode::plus(double left, double right)
{
	return left + right;
}

double BinaryOpNode::minus(double left, double right)
{
	return left - right;
}

double BinaryOpNode::multiply(double left, double right)
{
	return left * right;
}

double BinaryOpNode::divide(double left, double right)
{
	if (right == 0)
	{
		throw std::invalid_argument("It cannot be divided by zero!");
	}
	return left / right;
}

double BinaryOpNode::evaluate(VariableTable& evnironment)
{
	double left = _num1->evaluate(evnironment);
	double right = _num2->evaluate(evnironment);

	if (_operand == "+")
	{
		return plus(left, right);
	}
	else if (_operand == "-")
	{
		return minus(left, right);
	}
	else if (_operand == "*")
	{
		return multiply(left, right);
	}
	else if (_operand == "/")
	{
		return divide(left, right);
	}
	else
	{
		throw std::invalid_argument("Such opernad is not exist!");
	}
} 

BinaryOpNode::~BinaryOpNode()
{
	delete _num1;
	delete _num2;
}