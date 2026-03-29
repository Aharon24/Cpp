#include "ClapTrap.hpp"

#include "ScavTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "--- CONSTRUCTING ---" << std::endl;
    ClapTrap clap("Clappy");
    
    ScavTrap scav("Scavvy");

    std::cout << "\n--- TESTING BASIC INFO ---" << std::endl;
    clap.attack("a fly");
    scav.attack("an intruder");

    std::cout << "\n--- TESTING REPAIRS AND DAMAGE ---" << std::endl;
    scav.takeDamage(50);
    scav.beRepaired(20);
    
    scav.guardGate();

    std::cout << "\n--- TESTING COPY CONSTRUCTOR ---" << std::endl;
    ScavTrap scavCopy(scav);
    scavCopy.attack("the same intruder");

    std::cout << "\n--- TESTING ASSIGNMENT OPERATOR ---" << std::endl;
    ScavTrap scavAssign;
    scavAssign = scav;
    scavAssign.guardGate();

    std::cout << "\n--- DESTRUCTING ---" << std::endl;
    return 0;
}