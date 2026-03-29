#include "ClapTrap.hpp"

#include "ScavTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "----------------------------\n" << std::endl;
    ClapTrap clap("Clappy");
    ScavTrap scav("Scavvy");


    std::cout << "----------------------------\n" << std::endl;
    clap.attack("a fly");
    scav.attack("an intruder");


    std::cout << "----------------------------\n" << std::endl;
    scav.takeDamage(50);
    scav.beRepaired(20);
    
    std::cout << "----------------------------\n" << std::endl;
    scav.guardGate();

    std::cout << "----------------------------\n" << std::endl;
    ScavTrap scavCopy(scav);
    scavCopy.attack("the same intruder");

    std::cout << "----------------------------\n" << std::endl;
    ScavTrap scavAssign;
    scavAssign = scav;
    scavAssign.guardGate();

    return 0;
}