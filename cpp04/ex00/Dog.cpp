#include "DOG.hpp"


Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(std::string name) : Animal()
{
    this->type = name;
    std::cout << "Dog constructor called with "<< name << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
    type = other.type;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this == &other)
    {
        std::cout << "Dog copy assignment operator called   !!! but this == other" << std::endl;
        return *this;
    }
    Animal::operator=(other);
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
  std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound( void ) const
{
    std::cout << "Woof! Woof!" << std::endl;
}