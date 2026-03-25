#include "ScavTrap.hpp"




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
                << ", causing "  << hitPoints
                << " points of damage!\n";
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap is now in Gate keeper mode\n";
}