#pragma once
# include "AstNode.h"

class NumberNode : public AstNode
{
private:
	double _number;
public:
	NumberNode(double number);
	double evaluate(VariableTable& evnironment) override;
};