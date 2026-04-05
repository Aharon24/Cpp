#include "Brain.hpp"


Brain::Brain()
{
    std::cout << "Brain constructor" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "default";
}

Brain::Brain(std::string name)
{
    std::cout << "Brain constructor with" << name <<  std::endl;
    for (int i = 0; i < 100; i++) 
        this->ideas[i] = name;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain assignation operator" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor" << std::endl;
}


void Brain::setIdea(int index, const std::string &idea)
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}
std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return ideas[index];
    return "Wrong Index";
}