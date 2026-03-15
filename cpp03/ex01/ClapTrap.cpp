
#include "ClapTrap.hpp"

ClapTrap::~ClapTrap()
{

}

ClapTrap::ClapTrap()
{
    name = "Default";
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(std::string n): name(n)
{
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
     std::cout << "ClapTrap constructor called for " << name << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other)
{
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "ClapTrap copy constructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap copy assignment operator called\n";
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " can't attack because it has no hit points left!\n";
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy to attack!\n";
        return;
    }
    
    energyPoints--;
    std::cout   << "ClapTrap "   << name
                << " attacks "   << target
                << ", causing "  << hitPoints
                << " points of damage!\n";
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << "is already destroyed!\n";
        return;
    }
    if (amount >= static_cast<unsigned int>(hitPoints))
        hitPoints = 0;
    else
        hitPoints -= amount;

    std::cout << "ClapTrap " << name
              << " takes " << amount
              << " points of damage! "
              << "Remaining HP: " << attackDamage
              << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is destroyed and cannot be repaired!\n";
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy left to repair!\n";
        return;
    }
    hitPoints += amount;
    energyPoints--;

    std::cout << "ClapTrap " << name 
              << " repairs itself for " << amount 
              << " hit points! "
              << "Current HP: " << hitPoints
              << ", Energy: " << energyPoints
              << std::endl;
}
