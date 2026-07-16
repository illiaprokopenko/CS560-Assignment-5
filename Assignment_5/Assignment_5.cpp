#include <iostream>
#include <string>
#include <vector>
#include "TokenManager.h"
#include "Parser.h"

int main()
{
    std::string line = "12 + 25 * 4";
    std::string line2 = "var a = 115";
    std::string lin3 = "a / 5";
    std::vector<std::string> test = TokenManager::BreakToTokens(line);
    std::vector<std::string> test2 = TokenManager::BreakToTokens(line2);
    std::vector<std::string> test3 = TokenManager::BreakToTokens(lin3);

    for (int i = 0; i < test.size(); i++)
    {
        std::cout << test[i] << std::endl;
    }

    VariableTable env = VariableTable();
    Parser* parser = new Parser(test);
    AstNode* result = parser->Parse(env);
    parser = new Parser(test2);
    parser->Parse(env);
    parser = new Parser(test3);
    result = parser->Parse(env);

    std::cout << result->evaluate(env) << std::endl;
}