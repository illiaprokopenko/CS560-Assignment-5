#pragma once
# include "AstNode.h"
# include <string>
# include <vector>
# include "VariableTable.h"

class FunctionNode : public AstNode
{
private:
	std::string _funcName;
	std::vector<AstNode*> _args;

	double Minimum(double l, double r);
	double Maximum(double l, double r);
	double Power(double number, double degree);
	double Abs(double number);
public:
	FunctionNode(std::string funcName, std::vector<AstNode*> args);
	double evaluate(VariableTable& environment) override;
	~FunctionNode();
};