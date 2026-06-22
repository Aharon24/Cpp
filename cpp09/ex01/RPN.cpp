

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _stack = other._stack;
    return (*this);
}
void RPN::operator_and_check(std::string token)
{
    int a;
    int b;
    int res;

    if (_stack.size() < 2)
            throw std::runtime_error("Error");
    b = _stack.top(); _stack.pop();
    a = _stack.top(); _stack.pop();
    if (token == "+")
        res = a + b;
    else if (token == "-")
        res = a - b;
    else if (token == "*")
        res = a * b;
    else
    {
        if (b == 0)
            throw std::runtime_error("Error");
        res = a / b;
    }
    _stack.push(res);
}
int RPN::evaluate(const std::string& expr)
{
    while (!_stack.empty())
        _stack.pop();
    std::stringstream ss(expr);
    std::string token;
    int operatorCount = 0;
    int operandCount = 0;
    while (ss >> token)
    {
        if (token.size() == 1 && isdigit(token[0]))
        {
            _stack.push(token[0] - '0');
            operandCount++;
        }
        else if(token == "+" || token == "-" || token == "*" || token == "/")
        {
            operatorCount++;
            operator_and_check(token);
        }
        else
            throw std::runtime_error("Error");

    }
    if (_stack.size() != 1 || operatorCount == 0)
        throw std::runtime_error("Error");

    return _stack.top();
}

RPN::~RPN()
{
}