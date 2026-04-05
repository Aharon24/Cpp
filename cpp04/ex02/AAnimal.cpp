#include "AAnimal.hpp"


AAnimal::AAnimal()
{
    type = "AAnimal";
    std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string name) : type(name)
{
    std::cout << "AAnimal constructor called with "<< name << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{
    type = other.type;
    std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    if (this == &other)
        return *this;
    type = other.type;
    std::cout << "Animal copy assignment operator called" << std::endl;
    return *this;
}

AAnimal::~AAnimal()
{
  std::cout << "AAnimal: Destructor called" << std::endl;
}

std::string  AAnimal::getType() const
{
    return this->type;
}

