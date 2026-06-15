#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

int main()
{
    std::cout << "===== TEST 1: BASIC STACK =====" << std::endl;

    MutantStack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    std::cout << s.size() << std::endl;

    std::cout << "\n===== TEST 2: ITERATORS =====" << std::endl;

    for (int i = 1; i <= 5; i++)
        s.push(i);

    MutantStack<int>::iterator it = s.begin();
    MutantStack<int>::iterator ite = s.end();

    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    std::cout << "\n===== TEST 3: COPY TO STD::STACK =====" << std::endl;

    MutantStack<int> a;
    a.push(42);
    a.push(100);

    std::stack<int> b(a);

    std::cout << b.top() << std::endl;
    std::cout << b.size() << std::endl;

    std::cout << "\n===== TEST 4: COMPARE WITH LIST =====" << std::endl;

    MutantStack<int> ms;
    std::list<int> lst;

    for (int i = 0; i < 4; i++)
    {
        ms.push(i);
        lst.push_back(i);
    }

    MutantStack<int>::iterator it1 = ms.begin();
    std::list<int>::iterator it2 = lst.begin();

    while (it1 != ms.end() && it2 != lst.end())
    {
        std::cout << *it1 << " " << *it2 << std::endl;
        ++it1;
        ++it2;
    }

    std::cout << "\n===== TEST 5: EDGE CASE =====" << std::endl;

    MutantStack<int> e;
    e.push(1);

    std::cout << e.top() << std::endl;
    e.pop();
    std::cout << e.size() << std::endl;

    return 0;
}