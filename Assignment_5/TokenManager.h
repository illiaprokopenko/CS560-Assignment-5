#pragma once
# include <string>
# include <vector>

class TokenManager
{
public:
	static std::vector<std::string> BreakToTokens(std::string& expression);
	~TokenManager() = default;
};