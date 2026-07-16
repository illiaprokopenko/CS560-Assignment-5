#pragma once
# include <string>
# include <iostream>
# include "VariableTable.h"

class AstNode
{
public:
	virtual double evaluate(VariableTable& evnironment) = 0;
	virtual ~AstNode() = default;
};