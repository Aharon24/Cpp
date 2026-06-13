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

}

int Span::longestSpan() const
{
    int max;
    int min;

    if (_data.size() < 2)
        throw std::runtime_error("Not enough numbers");

    min = *std::min_element(_data.begin(), _data.end());
    max = *std::max_element(_data.begin(), _data.end());

    return (max - min);
}