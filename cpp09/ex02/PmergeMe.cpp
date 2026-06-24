#include "PmergeMe.hpp"


PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return (*this);
}



void PmergeMe::parseArguments(char **argv)
{
    long v;
    char *end;


    v = 0;
    while(*argv)
    {
        if (!isNumber(*argv))
            throw std::runtime_error("Error");
        
        v = std::strtol(*argv, &end, 10);

        if (*end != '\0')
            throw std::runtime_error("Error");

        if (v < 0)
            throw std::runtime_error("Error");

        if (v > INT_MAX)
                throw std::runtime_error("Error");

        _vec.push_back(static_cast<int>(v));
        _deq.push_back(static_cast<int>(v));
        ++argv;
    }

}

void PmergeMe::printBefore() const
{
    std::cout << "Before: ";

    for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


void PmergeMe::printAfter() const
{
    std::cout << "After: ";

    for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


bool PmergeMe::isNumber(const char *str) const
{
    if (*str == '\0')
        return false;

    while(*str)
    {
        if(!std::isdigit(*str))
            return (false);
        ++str;
    }
    return (true);

}


std::vector<Pair> PmergeMe::makePairsVector(const std::vector<int>& vec)
{
    std::vector<Pair> pairs;
    Pair p;
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        if (i + 1 < vec.size())
        {
            if(vec[i] < vec[i + 1])
            {
                p.small = vec[i];
                p.big = vec[i + 1];
            }
            else
            {
                p.small = vec[i + 1];
                p.big = vec[i];
            }
        }
        else
        {
            p.small = vec[i];
            p.big = -1;
        }
        pairs.push_back(p);
    }

    return (pairs);
}

std::vector<int> PmergeMe::mergeInsertSortVector(const std::vector<int>& input)
{
    if (input.size() <= 1)
        return (input);
    std::vector<Pair> pairs = makePairsVector(input);
    std::vector<int> mainChain;
    std::vector<int> pend;
    int odd = -1;

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].big != -1)
        {
            mainChain.push_back(pairs[i].big);
            pend.push_back(pairs[i].small);
        }
        else
            odd = pairs[i].small;
    }
    mainChain = mergeInsertSortVector(mainChain);

    for (size_t i = 0; i < pend.size(); ++i)
        insertWithBinarySearch(mainChain, pend[i]);

    if (odd != -1)
        insertWithBinarySearch(mainChain, odd);

    return mainChain;
}

const std::vector<int>& PmergeMe::getVec() const
{
    return _vec;
}

const std::deque<int>& PmergeMe::getDeq() const
{
    return _deq;
}

void PmergeMe::insertWithBinarySearch(std::vector<int>& vec, int value)
{
    size_t left = 0;
    size_t right = vec.size();

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (vec[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    vec.insert(vec.begin() + left, value);
}


void PmergeMe::sortVector()
{
    _vec = mergeInsertSortVector(_vec);
}

std::deque<Pair> PmergeMe::makePairsDeque(const std::deque<int>& deq)
{
    std::deque<Pair> pairs;
    Pair p;

    for (size_t i = 0; i < deq.size(); i += 2)
    {
        if (i + 1 < deq.size())
        {
            if (deq[i] < deq[i + 1])
            {
                p.small = deq[i];
                p.big = deq[i + 1];
            }
            else
            {
                p.small = deq[i + 1];
                p.big = deq[i];
            }
        }
        else
        {
            p.small = deq[i];
            p.big = -1;
        }
        pairs.push_back(p);
    }
    return pairs;
}

void PmergeMe::insertWithBinarySearch(std::deque<int>& deq, int value)
{
    size_t left = 0;
    size_t right = deq.size();
    size_t mid;

    while (left < right)
    {
        mid = left + (right - left) / 2;

        if (deq[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    deq.insert(deq.begin() + left, value);
}

std::deque<int> PmergeMe::mergeInsertSortDeque(const std::deque<int>& input)
{
    if (input.size() <= 1)
        return input;

    std::deque<Pair> pairs = makePairsDeque(input);

    std::deque<int> mainChain;
    std::deque<int> pend;
    int odd = -1;

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].big != -1)
        {
            mainChain.push_back(pairs[i].big);
            pend.push_back(pairs[i].small);
        }
        else
            odd = pairs[i].small;
    }

    mainChain = mergeInsertSortDeque(mainChain);

    for (size_t i = 0; i < pend.size(); ++i)
        insertWithBinarySearch(mainChain, pend[i]);

    if (odd != -1)
        insertWithBinarySearch(mainChain, odd);

    return mainChain;
}

void PmergeMe::sortDeque()
{
    _deq = mergeInsertSortDeque(_deq);
}

PmergeMe::~PmergeMe()
{
}