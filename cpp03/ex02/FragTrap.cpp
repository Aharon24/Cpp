#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap constructor called for " << name << "\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        this->ClapTrap::operator=(other);
    }
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    return *this;
}


void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " says: 'High five, guys! ✋'" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << this->name << "\n";
}


