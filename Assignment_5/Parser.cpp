#pragma once
# include "Parser.h"
# include "VariableNode.h"
# include "NumberNode.h"
# include "BinaryOpNode.h"
# include <cctype>
# include <stdexcept>

Parser::Parser(std::vector<std::string> t) : _tokens(t), _currentIndex(0) {}

bool Parser::isVariable(std::string token)
{
	if (token.length() == 0)
	{
		return false;
	}

	if (!isalpha(token[0]) && token[0] != '_')
	{
		return false;
	}

	if (token == "var" || token == "def")
	{
		return false;
	}

	for (int i = 0; i < token.length(); i++)
	{
		if (!isalnum(token[i]) && token[i] != '_')
		{
			return false;
		}
	}

	return true;
}

bool Parser::isDouble(std::string token)
{
	try 
	{
		size_t index = 0;
		std::stod(token, &index);

		return index == token.length();
	}
	catch (...)
	{
		return false;
	}
}

AstNode* Parser::Parse(VariableTable& environment)
{
	if (Peek() == "var")
	{
		_currentIndex++;
		std::string variableName = GetCurrent();
		
		if (!match("="))
		{
			std::runtime_error("Exptected '=' afte var");
		}

		AstNode* variableDef = ParseExpression();
		environment.InsertInto(variableName, variableDef->evaluate(environment));
		AstNode* variable = new VariableNode(variableName);
		delete variableDef;
		return variable;
	}

	AstNode* expressionResult = ParseExpression();

	return expressionResult;
}

AstNode* Parser::ParseTerm()
{
	AstNode* left = ParseFactor();
	AstNode* right;

	while (Peek() == "*" || Peek() == "/")
	{
		std::string operand = GetCurrent();
		right = ParseFactor();
		left = new BinaryOpNode(operand, left, right);
	}
	return left;
}

AstNode* Parser::ParseExpression()
{
	AstNode* left = ParseTerm();
	AstNode* right;

	while (Peek() == "+" || Peek() == "-")
	{
		std::string operand = GetCurrent();
		right = ParseTerm();
		left = new BinaryOpNode(operand, left, right);
	}
	return left;
}

AstNode* Parser::ParseFactor()
{	
	std::string token = Peek();

	if (isDouble(token))
	{
		double num = std::stod(GetCurrent());
		AstNode* number = new NumberNode(num);
		return number;
	}
	else if (isVariable(token))
	{
		AstNode* variable = new VariableNode(GetCurrent());
		return variable;
	}
	else if (Peek() == "(")
	{
		GetCurrent();
		AstNode* expression = ParseExpression();
		if (GetCurrent() != ")")
		{
			delete expression;
			throw std::runtime_error("The bracket is not closed!");
		}
		return expression;
	}
	else
	{
		throw std::runtime_error("Token does not exist!");
	}
}

std::string Parser::Peek()
{
	if (_currentIndex >= _tokens.size())
	{
		return "";
	}
	return _tokens[_currentIndex];
}

std::string Parser::GetCurrent()
{
	std::string result = Peek();
	_currentIndex++;
	return result;

}

bool Parser::match(std::string exptected)
{
	if (exptected == Peek())
	{
		_currentIndex++;
		return true;
	};
	return false;
}

