#include <vector>
#include <iostream>
#include "easyfind.hpp"


int main()
{
    std::vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Found: " << *it << std::endl;

        easyfind(v, 999);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}