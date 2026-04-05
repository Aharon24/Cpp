
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
protected:
    std::string type;
public:
    AAnimal();
    AAnimal(std::string name);
    AAnimal(const AAnimal& other);
    AAnimal& operator=(const AAnimal& other);
    virtual ~AAnimal();
    
public:
    virtual void makeSound( void ) const = 0;
    std::string getType() const;

};


#endif