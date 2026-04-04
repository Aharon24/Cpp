#include "Animal.hpp"


Animal::Animal()
{
    type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string name) : type(name)
{
    std::cout << "Animal constructor called with "<< name << std::endl;
}

Animal::Animal(const Animal& other)
{
    type = other.type;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this == &other)
        return *this;
    type = other.type;std::cout << "Animal copy assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal()
{
  std::cout << "Animal: Destructor called" << std::endl;
}

void Animal::makeSound( void ) const
{
    std::cout << "*generic animal sound*" << std::endl;
}

std::string  Animal::getType() const
{
    return this->type;
}

