#include "Array.hpp"
#include <iostream>

int main()
{
    std::cout << "----- CREATE ARRAY -----" << std::endl;

    Array<int> a(5);

    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i * 10;

    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << std::endl;

    std::cout << "\n----- COPY TEST -----" << std::endl;

    Array<int> b(a);

    b[0] = 999;

    std::cout << "a[0] = " << a[0] << std::endl;
    std::cout << "b[0] = " << b[0] << std::endl;

    std::cout << "\n----- ASSIGNMENT TEST -----" << std::endl;

    Array<int> c;
    c = a;

    c[1] = 888;

    std::cout << "a[1] = " << a[1] << std::endl;
    std::cout << "c[1] = " << c[1] << std::endl;

    std::cout << "\n----- EXCEPTION TEST -----" << std::endl;

    try
    {
        std::cout << a[100] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "exception caught" << std::endl;
    }

    std::cout << "\n----- CONST TEST -----" << std::endl;

    const Array<int> d(3);

    for (unsigned int i = 0; i < d.size(); i++)
        std::cout << d[i] << std::endl;

    return 0;
}