# include "VariableTable.h"
# include <iostream>

void VariableTable::InsertInto(std::string varName, double number)
{
	if (_varDict.contains(varName))
	{
		std::cout << "This variable already exists" << std::endl;
		return;
	}

	_varDict[varName] = number;
}

void VariableTable::DeleteByKey(std::string varName)
{
	if (!_varDict.erase(varName))
	{
		std::cout << "Variable does not exist" << std::endl;
	}
}

double VariableTable::GetByKey(std::string varName)
{
	if (!_varDict.contains(varName))
	{
		throw std::invalid_argument("Variable doesn't exist");
	}
	return _varDict[varName];
}