#pragma once
# include "AstNode.h"
# include <string>

class BinaryOpNode : public AstNode
{
private:
	std::string _operand;
	AstNode* _num1;
	AstNode* _num2;

	double plus(double l, double r);
	double minus(double l, double r);
	double multiply(double l, double r);
	double divide(double l, double r);

public:
	BinaryOpNode(std::string operand, AstNode* num1, AstNode* num2);
	double evaluate(VariableTable& evnironment) override;
	~BinaryOpNode();
};