
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
    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();


    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;

    friend std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
};

#endif
