#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

int main()
{
    try
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // -------------------------------
        // TEST RANGE INSERT
        // -------------------------------
        std::vector<int> vec;
        for (int i = 0; i < 10000; i++)
            vec.push_back(rand() % 100000 + 1);

        Span bigSpan(10000);
        bigSpan.addNumbers(vec.begin(), vec.end());

        std::cout << "Big span OK" << std::endl;

        std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest: " << bigSpan.longestSpan() << std::endl;

        // -------------------------------
        // ERROR TEST (overflow)
        // -------------------------------
        Span small(2);
        small.addNumber(1);
        small.addNumber(2);

        // this should throw
        small.addNumber(3);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}