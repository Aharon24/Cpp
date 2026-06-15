#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
    while (begin != end)
    {
        if (_data.size() >= N_len)
            throw std::runtime_error("Span is full");

        _data.push_back(*begin);
        ++begin;
    }
}

#endif