#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(std::string name);
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

public:
    void makeSound( void ) const;
};


#endif
