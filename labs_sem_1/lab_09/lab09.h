#ifndef LAB09_H
#define LAB09_H

#include <vector>
#include <string>
#include <stack>
#include <map>

class PolishNotation
{
public:
    std::vector<std::string> convertToPostfix(const std::string& expression);
    double evaluateExpression(const std::vector<std::string>& postfix, double x);
    bool checkExpression(const std::string& expr, std::string& message);
    bool findVariable(const std::string& expr);

private:
    std::map<char, int> operations = {
        {'+', 1}, {'-', 1},
        {'*', 2}, {'/', 2},
        {'^', 3}
    };

    std::vector<std::string> functions = {"sin", "cos", "tan", "ctg", "exp", "sqrt"};

    bool checkBrackets(const std::string& expr);
    bool checkOperators(const std::string& expr);
    bool checkSymbols(const std::string& expr);
    bool isOperation(char c);
    bool isMathFunction(const std::string& word);
};

#endif