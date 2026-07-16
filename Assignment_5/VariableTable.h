#pragma once
# include <string>
# include <map>

class VariableTable
{
private:
	std::map<std::string, double> _varDict;
public:
	double GetByKey(std::string varName);
	void InsertInto(std::string varName, double number);
	void DeleteByKey(std::string varName);
};