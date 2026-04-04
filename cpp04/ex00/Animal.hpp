
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(std::string name);
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();
    
public:
    virtual void makeSound( void ) const;
    std::string getType() const;

};


#endif