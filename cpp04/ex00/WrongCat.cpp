#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() 
{
    this->type = "WrongCat";
    std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string name) : WrongAnimal(name) 
{
    this->type = name;
    std::cout << "WrongCat: Name constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) 
{
    std::cout << "WrongCat: Copy constructor called" << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) 
{
    std::cout << "WrongCat: Assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

WrongCat::~WrongCat() 
{
    std::cout << "WrongCat: Destructor called" << std::endl;
}

void WrongCat::makeSound() const 
{
    std::cout << "Wrong Meow! (You shouldn't hear this via WrongAnimal pointer)" << std::endl;
}