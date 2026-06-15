#include "Span.hpp"


Span::Span(unsigned int N): N_len(N)
{

}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        N_len = other.N_len;
        _data = other._data;
    }
    return *this;
 }

void Span::addNumber(int n)
{
    if(_data.size() >= N_len)
        throw std::runtime_error("Span is full");
    _data.push_back(n);
}

int Span::shortestSpan() const
{
    int min_m;
    int c;
    


    if (_data.size() < 2)
        throw std::runtime_error("Not enough numbers");
    std::vector<int> copy = _data;
    std::sort(copy.begin(), copy.end());
    min_m = copy[1] - copy[0];
    for(size_t i = 1; i < copy.size(); i++)
    {
        c = copy[i] - copy[i - 1];
        if(c < min_m)
            min_m = c;
    }

    return (min_m);
}

int Span::longestSpan() const
{
    int max_m;
    int min_m;

    if (_data.size() < 2)
        throw std::runtime_error("Not enough numbers");

    min_m = *std::min_element(_data.begin(), _data.end());
    max_m = *std::max_element(_data.begin(), _data.end());

    return (max_m - min_m);
}

Span::~Span()
{

}