#pragma once
# include "TokenManager.h"

std::vector<std::string> TokenManager::BreakToTokens(std::string& expression)
{
    std::vector<std::string> tokens;
    std::string part = "";


    for (int i = 0; i < expression.length(); i++)
    {

        if (std::isalnum(expression[i]) || expression[i] == '.')
        {
            part += expression[i];
        }
        else if (expression[i] != ' ' && part.length() != 0)
        {
            tokens.push_back(part);
            tokens.push_back({ expression[i] });
            part = "";
        }
        else if (expression[i] == ' ' && part.length() != 0)
        {
            tokens.push_back(part);
            part = "";
        }
        else if (expression[i] != ' ')
        {
            tokens.push_back({ expression[i] });
        }
    }

    if (part.length() != 0)
    {
        tokens.push_back(part);
    }

    return tokens;
}