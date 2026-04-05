#include "Dog.hpp"


Dog::Dog() : Animal()
{
    type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(std::string name) : Animal()
{
    this->type = name;
    this->brain = new Brain();
    std::cout << "Dog constructor called with "<< name << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
    type = other.type;
    if (other.brain)
        this->brain = new Brain(*other.brain);
    else
        this->brain = new Brain();
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
    delete this->brain;
    if (other.brain)
        this->brain = new Brain(*other.brain);
    else
        this->brain = new Brain();
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound( void ) const
{
    std::cout << "Woof! Woof!" << std::endl;
}

void Dog::setIdea(int index, std::string idea)
{
    this->brain->setIdea(index, idea);
}
std::string Dog::getIdea(int index) const
{
    return this->brain->getIdea(index);
}

Brain* Dog::getBrain() const
{
    return this->brain;
}