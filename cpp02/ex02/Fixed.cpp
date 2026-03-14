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
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this == &other)
        return (*this);
    number = other.getRawBits();
    return (*this);
}

Fixed::Fixed(const int n)
{
    number = n << _fractionalBits;
}


Fixed::Fixed(const float n)
{
    number = roundf(n * (1 << _fractionalBits));
}

int Fixed::getRawBits(void) const
{
    return (number);
}

void Fixed::setRawBits(int const raw)
{
    number = raw;
}

///  >, <, >=, <=, ==, and !=.

bool Fixed::operator>(const Fixed& other) const
{
    return (this->number > other.number);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->number < other.number);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->number >= other.number);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->number <= other.number);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->number == other.number);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->number != other.number);
}


//  + - * /

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed r;
    r.setRawBits(this->number + other.number);
    return (r);
}
Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed r;
    r.setRawBits(this->number - other.number);
    return (r);
}
Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed r;
    long tmp = (long)this->number * (long)other.number;
    (r).setRawBits((int)(tmp >> _fractionalBits));
    return (r);

}
Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed r;
    long tmp = ((long)this->number << _fractionalBits) / other.number;
    r.setRawBits((int)tmp);
    return (r);
}


std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out; 
}

float Fixed::toFloat( void ) const
{
    return ((float)number / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const
{
    return number >> _fractionalBits;
}



// ------------------ Prefix Increment/Decrement ------------------
Fixed& Fixed::operator++() // ++a
{
    number++;
    return *this;
}

Fixed& Fixed::operator--() // --a
{
    number--;
    return *this;
}

// ------------------ Postfix Increment/Decrement ------------------
Fixed Fixed::operator++(int) // a++
{
    Fixed temp = *this; 
    number++;         
    return temp;       
}

Fixed Fixed::operator--(int) // a--
{
    Fixed temp = *this; 
    number--;         
    return temp;        
}


Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;    
    return b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    return b;
}
    // max

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    return b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    return b;
}