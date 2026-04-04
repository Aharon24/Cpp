#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() 
{
    type = "WrongAnimal";
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : type("WrongAnimal") 
{
    std::cout << "Animal constructor called with "<< name << std::endl;
}

WrongAnimal::~WrongAnimal() 
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->type = other.type; // Используем оператор присваивания, чтобы не дублировать код
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) 
{
    if (this != &other)
        this->type = other.type;
    type = other.type;std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sounds (static noise) ---" << std::endl;
}

std::string WrongAnimal::getType() const 
{
    return this->type;
}