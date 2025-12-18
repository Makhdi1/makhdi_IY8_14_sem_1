#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <vector>
#include <cctype>
#include <map>

using namespace std;

bool check_balance(string expr) {
    int balance = 0;
    for (char c : expr) {
        if (c == '(') balance++;
        if (c == ')') balance--;
        if (balance < 0) return false;
    }
    return balance == 0;
}

bool check_chars(string expr) {
    for (char c : expr) {
        if (!isdigit(c) && !isalpha(c) &&
            c != '+' && c != '-' && c != '*' &&
            c != '/' && c != '(' && c != ')' &&
            c != '.' && c != ' ') {
            return false;
        }
    }
    return true;
}

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int get_priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string to_rpn(string expr) {
    stack<char> ops;
    string result;

    for (size_t i = 0; i < expr.length(); i++) {
        char c = expr[i];

        if (isdigit(c) || c == '.' || c == 'x') {
            result += c;
            if (i == expr.length() - 1 || (!isdigit(expr[i + 1]) && expr[i + 1] != '.')) {
                result += ' ';
            }
        }
        else if (c == '(') {
            ops.push(c);
        }
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                result += ops.top();
                result += ' ';
                ops.pop();
            }
            ops.pop();
        }
        else if (is_operator(c)) {
            while (!ops.empty() && get_priority(ops.top()) >= get_priority(c)) {
                result += ops.top();
                result += ' ';
                ops.pop();
            }
            ops.push(c);
        }
    }

    while (!ops.empty()) {
        result += ops.top();
        result += ' ';
        ops.pop();
    }

    return result;
}

double calculate_rpn(string rpn, double x_value) {
    stack<double> nums;

    for (size_t i = 0; i < rpn.length(); i++) {
        char c = rpn[i];

        if (isdigit(c) || c == '.') {
            string num;
            while (i < rpn.length() && (isdigit(rpn[i]) || rpn[i] == '.')) {
                num += rpn[i];
                i++;
            }
            nums.push(stod(num));
            i--;
        }
        else if (c == 'x') {
            nums.push(x_value);
        }
        else if (is_operator(c)) {
            if (nums.size() < 2) {
                cout << "Error: not enough operands" << endl;
                return 0;
            }

            double b = nums.top(); nums.pop();
            double a = nums.top(); nums.pop();

            switch (c) {
                case '+': nums.push(a + b); break;
                case '-': nums.push(a - b); break;
                case '*': nums.push(a * b); break;
                case '/':
                    if (b == 0) {
                        cout << "Error: division by zero" << endl;
                        return 0;
                    }
                    nums.push(a / b);
                    break;
                case '^': nums.push(pow(a, b)); break;
            }
        }
    }

    if (nums.empty()) {
        cout << "Error: no result" << endl;
        return 0;
    }

    return nums.top();
}

void replace_functions(string& expr) {
    size_t pos;

    while ((pos = expr.find("sin")) != string::npos) {
        expr.replace(pos, 3, "s");
    }
    while ((pos = expr.find("cos")) != string::npos) {
        expr.replace(pos, 3, "c");
    }
    while ((pos = expr.find("tg")) != string::npos) {
        expr.replace(pos, 2, "t");
    }
    while ((pos = expr.find("ctg")) != string::npos) {
        expr.replace(pos, 3, "g");
    }
    while ((pos = expr.find("exp")) != string::npos) {
        expr.replace(pos, 3, "e");
    }
}

void process_unary_minus(string& expr) {
    if (expr[0] == '-') {
        expr[0] = '~';
    }

    for (size_t i = 1; i < expr.length(); i++) {
        if (expr[i] == '-' && (expr[i - 1] == '(' || is_operator(expr[i - 1]))) {
            expr[i] = '~';
        }
    }
}

bool has_variable(string expr) {
    return expr.find('x') != string::npos;
}

bool validate_expression(string expr) {
    if (!check_balance(expr)) {
        cout << "Error: unbalanced parentheses" << endl;
        return false;
    }

    if (!check_chars(expr)) {
        cout << "Error: invalid characters" << endl;
        return false;
    }

    return true;
}

int main() {
    cout << "String Calculator" << endl;
    cout << "Enter expression (0 to exit): ";

    string expr;
    getline(cin, expr);

    while (expr != "0") {
        if (!validate_expression(expr)) {
            cout << "Enter expression: ";
            getline(cin, expr);
            continue;
        }

        replace_functions(expr);
        process_unary_minus(expr);

        double x_value = 0;
        if (has_variable(expr)) {
            cout << "Enter x value: ";
            cin >> x_value;
            cin.ignore();
        }

        string rpn = to_rpn(expr);
        double result = calculate_rpn(rpn, x_value);

        cout << "Result: " << result << endl;
        cout << "Enter expression: ";
        getline(cin, expr);
    }

    return 0;
}