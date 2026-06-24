#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <stdexcept>


struct Pair
{
    int small;
    int big;
};

class PmergeMe
{
private:
    std::vector<int> _vec;
    std::deque<int> _deq;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    bool isNumber(const char *str) const;

    void parseArguments(char **argv);
    void sortVector();
    void sortDeque();

    void printBefore() const;
    void printAfter() const;

    const std::vector<int>& getVec() const;
    const std::deque<int>& getDeq() const;


    std::vector<Pair> makePairsVector(const std::vector<int>& vec);
    std::vector<int> mergeInsertSortVector(const std::vector<int>& input);

    std::deque<Pair> makePairsDeque(const std::deque<int>& deq);
    std::deque<int> mergeInsertSortDeque(const std::deque<int>& input);
    void insertWithBinarySearch(std::vector<int>& vec, int value);
    void insertWithBinarySearch(std::deque<int>& deq, int value);

};

#endif