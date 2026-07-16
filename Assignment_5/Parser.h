#pragma once
#include <vector>
#include <string>
# include "AstNode.h"
# include "VariableNode.h"

class Parser
{
private:
	std::vector<std::string> _tokens;
	size_t _currentIndex = 0;
	bool isDouble(std::string token);
	bool isVariable(std::string token);
	bool isFunction(std::string token);
	AstNode* createFunction();
public:
	Parser(std::vector<std::string> tokens);
	std::string Peek();
	std::string GetCurrent();
	bool match(std::string exptected);
	AstNode* ParseExpression();
	AstNode* ParseTerm();
	AstNode* ParseFactor();
	AstNode* Parse(VariableTable& environment);
};