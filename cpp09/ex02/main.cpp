#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe pm;

    try
    {
        pm.parseArguments(argv + 1);

        pm.printBefore();

        // ===== VECTOR TIME =====
        clock_t start_v = clock();
        pm.sortVector();
        clock_t end_v = clock();

        double time_v = (double)(end_v - start_v)
                      / CLOCKS_PER_SEC
                      * 1e6;

        // ===== DEQUE TIME =====
        clock_t start_d = clock();
        pm.sortDeque();
        clock_t end_d = clock();

        double time_d = (double)(end_d - start_d)
                      / CLOCKS_PER_SEC
                      * 1e6;

        pm.printAfter();

        std::cout << std::fixed << std::setprecision(5);

        std::cout << "Time to process a range of "
                  << argc - 1
                  << " elements with std::vector : "
                  << time_v << " us" << std::endl;

        std::cout << "Time to process a range of "
                  << argc - 1
                  << " elements with std::deque : "
                  << time_d << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}