
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int number;
    static const int _fractionalBits = 8;
    
public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed(const int n);
    Fixed(const float n);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
    friend std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

    /// The 6 comparison operators: >, <, >=, <=, ==, and !=
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    ///The 4 arithmetic operators: +, -, *, and /
    // arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

};

#endif
