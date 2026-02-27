#include "HumanB.hpp"

void HumanB::attack( void )const
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack" << std::endl;

}

HumanB::~HumanB()
{
    weapon = NULL;
}
HumanB::HumanB(const std::string& n)
{
    this->name = n;
}
void HumanB::setWeapon(Weapon& w)
{
    this->weapon = &w;
}