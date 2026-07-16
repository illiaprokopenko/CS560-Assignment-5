# include "NumberNode.h"

NumberNode::NumberNode(double number) : _number(number){}

double NumberNode::evaluate(VariableTable& evnironment)
{
	return _number;
}