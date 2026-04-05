#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{

private:
    Brain* brain;

public:
    Dog();
    Dog(std::string name);
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

public:
    void makeSound( void ) const;
    Brain* getBrain() const;
    void setIdea(int index, std::string idea);
    std::string getIdea(int index) const;
};


#endif
