#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <vector>

class RPN
{
private:
    std::stack<int> _stack;

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    void operator_and_check(std::string token);
    int evaluate(const std::string& expr);
};

#endif