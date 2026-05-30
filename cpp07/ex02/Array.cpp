#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    _array = NULL;
    _size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    _size = n;
    _array = new T[n];
}

template <typename T>
Array<T>::Array(const Array& other)
{
     _size = other._size;
    _array = new T[_size];

    for (unsigned int i = 0; i < _size; i++)
        _array[i] = other._array[i];
}