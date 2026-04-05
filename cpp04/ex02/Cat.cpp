#include "Cat.hpp"


Cat::Cat() : AAnimal()
{
    type = "Cat";
    brain = new Brain("Cat");
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(std::string name) : AAnimal()
{
    this->type = name;
    brain = new Brain(name);
    std::cout << "Cat constructor called with "<< name << std::endl;
}

Cat::Cat(const Cat& other): AAnimal(other)
{
    if (other.brain)
        this->brain = new Brain(*other.brain);
    else
        this->brain = new Brain();
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this == &other)
    {
        std::cout << "Cat copy assignment operator called   !!! but this == other" << std::endl;
        return *this;
    }
    AAnimal::operator=(other);
    delete brain;
    if (other.brain)
        this->brain = new Brain(*other.brain);
    else
        this->brain = new Brain();
    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor called" << std::endl;
    delete brain; 
}

void Cat::makeSound( void ) const
{
    std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
    return brain;
}

void Cat::setIdea(int index, std::string idea)
{
    this->brain->setIdea(index, idea);
}

std::string  Cat::getIdea(int index) const
{
    return this->brain->getIdea(index);
}