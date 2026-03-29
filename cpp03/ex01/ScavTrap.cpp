#include "ScavTrap.hpp"

ScavTrap:: ScavTrap() : ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap constructor called for " << this->name << "\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap destructor called for " << this->name << "\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints <= 0)
    {
        std::cout << "ScavTrap " << name << " can't attack because it has no hit points left!\n";
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "ScavTrap " << name << " has no energy to attack!\n";
        return;
    }
    energyPoints--;
    std::cout   << "ScavTrap "   << name
                << " attacks "   << target
                << ", causing "  << attackDamage
                << " points of damage!\n";
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode\n";
}