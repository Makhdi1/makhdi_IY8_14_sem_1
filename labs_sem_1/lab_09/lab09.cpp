#include "lab09.h"
#include <cctype>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <cstring>

std::vector<std::string> PolishNotation::convertToPostfix(const std::string& expression)
{
    std::vector<std::string> output;
    std::stack<std::string> stack;
    std::string expr = expression;
    
    size_t pos = 0;
    while ((pos = expr.find("(-", pos)) != std::string::npos)
    {
        expr.replace(pos, 2, "(0-");
        pos += 3;
    }
    
    if (!expr.empty() && expr[0] == '-')
    {
        expr = "0" + expr;
    }
    
    for (size_t i = 0; i < expr.length(); i++)
    {
        char current = expr[i];
        
        if (current == ' ')
        {
            continue;
        }
        
        if (std::isdigit(current) || current == '.')
        {
            std::string number;
            while (i < expr.length() && (std::isdigit(expr[i]) || expr[i] == '.'))
            {
                number += expr[i];
                i++;
            }
            i--;
            output.push_back(number);
        }
        else if (current == 'x' || current == 'X')
        {
            output.push_back("x");
        }
        else if (std::isalpha(current))
        {
            std::string word;
            while (i < expr.length() && std::isalpha(expr[i]))
            {
                word += expr[i];
                i++;
            }
            i--;
            
            if (isMathFunction(word))
            {
                stack.push(word);
            }
        }
        else if (current == '(')
        {
            stack.push("(");
        }
        else if (current == ')')
        {
            while (!stack.empty() && stack.top() != "(")
            {
                output.push_back(stack.top());
                stack.pop();
            }
            stack.pop();
            
            if (!stack.empty() && isMathFunction(stack.top()))
            {
                output.push_back(stack.top());
                stack.pop();
            }
        }
        else if (operations.count(current))
        {
            while (!stack.empty() && stack.top() != "(" &&
                   operations[stack.top()[0]] >= operations[current])
            {
                output.push_back(stack.top());
                stack.pop();
            }
            stack.push(std::string(1, current));
        }
    }
    
    while (!stack.empty())
    {
        output.push_back(stack.top());
        stack.pop();
    }
    
    return output;
}

double PolishNotation::evaluateExpression(const std::vector<std::string>& postfix, double x)
{
    std::stack<double> values;
    
    for (const std::string& token : postfix)
    {
        if (std::isdigit(token[0]) || (token[0] == '.' && token.length() > 1))
        {
            values.push(std::stod(token));
        }
        else if (token == "x")
        {
            values.push(x);
        }
        else if (token.length() == 1 && operations.count(token[0]))
        {
            double second = values.top();
            values.pop();
            double first = values.top();
            values.pop();
            
            switch (token[0])
            {
                case '+': values.push(first + second); break;
                case '-': values.push(first - second); break;
                case '*': values.push(first * second); break;
                case '/':
                    if (second == 0) throw std::runtime_error("Division by zero");
                    values.push(first / second);
                    break;
                case '^': values.push(std::pow(first, second)); break;
            }
        }
        else if (isMathFunction(token))
        {
            double value = values.top();
            values.pop();
            
            if (token == "sin") values.push(std::sin(value));
            else if (token == "cos") values.push(std::cos(value));
            else if (token == "tan") values.push(std::tan(value));
            else if (token == "ctg") values.push(1.0 / std::tan(value));
            else if (token == "exp") values.push(std::exp(value));
            else if (token == "sqrt")
            {
                if (value < 0) throw std::runtime_error("Negative under sqrt");
                values.push(std::sqrt(value));
            }
        }
    }
    
    return values.top();
}

bool PolishNotation::checkExpression(const std::string& expr, std::string& message)
{
    std::string temp = expr;
    temp.erase(std::remove(temp.begin(), temp.end(), ' '), temp.end());
    
    if (temp.empty())
    {
        message = "Empty expression";
        return false;
    }
    
    if (!checkSymbols(temp))
    {
        message = "Invalid symbols";
        return false;
    }
    
    if (!checkBrackets(temp))
    {
        message = "Wrong brackets";
        return false;
    }
    
    if (!checkOperators(temp))
    {
        message = "Two operators in row";
        return false;
    }
    
    for (const std::string& func : functions)
    {
        size_t pos = 0;
        while ((pos = temp.find(func, pos)) != std::string::npos)
        {
            if (pos + func.length() < temp.length())
            {
                if (temp[pos + func.length()] != '(')
                {
                    message = "Wrong function use";
                    return false;
                }
            }
            else
            {
                message = "Wrong function use";
                return false;
            }
            pos += func.length();
        }
    }
    
    return true;
}

bool PolishNotation::findVariable(const std::string& expr)
{
    return expr.find('x') != std::string::npos || expr.find('X') != std::string::npos;
}

bool PolishNotation::checkBrackets(const std::string& expr)
{
    int balance = 0;
    for (char c : expr)
    {
        if (c == '(') balance++;
        else if (c == ')') balance--;
        if (balance < 0) return false;
    }
    return balance == 0;
}

bool PolishNotation::checkOperators(const std::string& expr)
{
    for (size_t i = 0; i < expr.length() - 1; i++)
    {
        if (strchr("+-*/^", expr[i]) && strchr("+-*/^", expr[i + 1]))
        {
            return false;
        }
    }
    return true;
}

bool PolishNotation::checkSymbols(const std::string& expr)
{
    for (char c : expr)
    {
        if (!std::isalnum(c) && !strchr("+-*/.^()_", c) && c != ' ')
        {
            return false;
        }
    }
    return true;
}

bool PolishNotation::isOperation(char c)
{
    return operations.count(c) > 0;
}

bool PolishNotation::isMathFunction(const std::string& word)
{
    return std::find(functions.begin(), functions.end(), word) != functions.end();
}