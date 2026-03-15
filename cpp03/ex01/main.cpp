#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a;
    ClapTrap b(a);
    ClapTrap c;
    c = a;

    a.attack("Anna");
    a.takeDamage(10);
    a.takeDamage(10);
    b.beRepaired(20);
}