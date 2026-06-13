#ifndef SPAN_HPP
#define SPAN_HPP


#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
private:
    unsigned int N_len;
    std::vector<int> _data;

public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int n);
    int shortestSpan() const;
    int longestSpan() const;
};



#endif