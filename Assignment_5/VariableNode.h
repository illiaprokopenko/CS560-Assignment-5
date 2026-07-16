#pragma once
# include "AstNode.h"
# include "VariableTable.h"

class VariableNode : public AstNode
{
private:
	std::string _varName;
public:
	VariableNode(std::string varName);
	double evaluate(VariableTable& environment) override;
};