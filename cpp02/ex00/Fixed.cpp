#include "Fixed.hpp"


Fixed::Fixed()
{
    number = 0;
}

Fixed::~Fixed()
{
}
Fixed::Fixed(const Fixed& other)
{
    number = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this == &other)
        return (*this);
    number = other.getRawBits();
    return (*this);
}


int Fixed::getRawBits(void) const
{
    return (number);
}

void Fixed::setRawBits(int const raw)
{
    
}
