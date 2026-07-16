# include "VariableNode.h"

VariableNode::VariableNode(std::string varName) : _varName(varName) {}

double VariableNode::evaluate(VariableTable& environment)
{
	return environment.GetByKey(_varName);
}