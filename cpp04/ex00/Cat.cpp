#include "Cat.hpp"


Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(std::string name) : Animal()
{
    this->type = name;
    std::cout << "Cat constructor called with "<< name << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
    type = other.type;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this == &other)
    {
        std::cout << "Cat copy assignment operator called   !!! but this == other" << std::endl;
        return *this;
    }
    Animal::operator=(other);
    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
  std::cout << "Cat: Destructor called" << std::endl;
}

void Cat::makeSound( void ) const
{
    std::cout << "Meow! Meow!" << std::endl;
}