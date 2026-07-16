# include "FunctionNode.h"
# include <algorithm>
# include <cmath>

FunctionNode::FunctionNode(std::string funcName, std::vector<AstNode*> args) : _funcName(funcName), _args(args) {}

double FunctionNode::Minimum(double l, double r)
{
	return std::min(l, r);
}

double FunctionNode::Maximum(double l, double r)
{
	return std::max(l, r);
}

double FunctionNode::Abs(double number)
{
	return std::abs(number);
}

double FunctionNode::Power(double number, double degree)
{
	return std::pow(number, degree);
}


double FunctionNode::evaluate(VariableTable& environment)
{
	std::vector<double> convertedArgs;

	for (int i = 0; i < _args.size(); i++)
	{
		convertedArgs.push_back(_args[i]->evaluate(environment));
	}

	if (_funcName == "max")
	{
		if (_args.size() != 2)
		{
			throw std::invalid_argument("Number of arguments is less than expected!");
		}
		return Maximum(convertedArgs[0], convertedArgs[1]);
	}
	else if (_funcName == "min")
	{
		if (_args.size() != 2)
		{
			throw std::invalid_argument("Number of arguments is less than expected!");
		}
		return Minimum(convertedArgs[0], convertedArgs[1]);
	}
	else if (_funcName == "pow")
	{
		if (_args.size() != 2)
		{
			throw std::invalid_argument("Number of arguments is less than expected!");
		}
		return Power(convertedArgs[0], convertedArgs[1]);
	}
	else if (_funcName == "abs")
	{
		if (_args.size() != 1)
		{
			throw std::invalid_argument("Number of arguments is less than expected!");
		}
		return Abs(convertedArgs[0]);
	}
	throw std::runtime_error("Function is not defined");
}

FunctionNode::~FunctionNode()
{
	for (int i = 0; i < _args.size(); i++)
	{
		delete _args[i];
	}
	_args.clear();
}