
#ifndef WrongANIMAL_HPP
#define WrongANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(std::string name);
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal();
    
public:
    void makeSound( void ) const;
    std::string getType() const;
};


#endif