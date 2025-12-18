#include "lab09.h"
#include <iostream>
#include <limits>

int main()
{
    PolishNotation calculator;
    std::string input;

    std::cout << "Calculator" << std::endl;
    std::cout << "Operations: + - * / ^" << std::endl;
    std::cout << "Functions: sin, cos, tan, ctg, exp, sqrt" << std::endl;
    std::cout << "Variable: x" << std::endl;
    std::cout << "Enter expression: ";

    std::getline(std::cin, input);

    std::string error;
    if (!calculator.checkExpression(input, error))
    {
        std::cout << "Error: " << error << std::endl;
        return 1;
    }

    bool hasX = calculator.findVariable(input);
    double xValue = 0;

    if (hasX)
    {
        std::cout << "Enter x value: ";
        while (!(std::cin >> xValue))
        {
            std::cout << "Invalid input. Enter number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    try
    {
        std::vector<std::string> postfix = calculator.convertToPostfix(input);

        std::cout << "Postfix notation: ";
        for (size_t i = 0; i < postfix.size(); i++)
        {
            std::cout << postfix[i];
            if (i < postfix.size() - 1)
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;

        double result = calculator.evaluateExpression(postfix, xValue);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}