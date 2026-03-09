#include "Fixed.hpp"


Fixed::Fixed()
{ 
    std::cout << "Default constructor called"  << std::endl;
    number = 0;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    number = n << _fractionalBits;
}


Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    number = roundf(n * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called"  << std::endl;
}
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called"  << std::endl;
    *this = other;;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called"  << std::endl;
    if (this == &other)
        return (*this);
    number = other.number;
    return (*this);
}


int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called"  << std::endl;
    return (number);
}

void Fixed::setRawBits(int const raw)
{
    number = raw;
}

float Fixed::toFloat( void ) const
{
    return ((float)number / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const
{
    return number >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out; 
}