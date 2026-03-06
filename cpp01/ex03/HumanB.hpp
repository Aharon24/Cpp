
#ifndef HUMANB
#define HUMANB

#include "Weapon.hpp"
class  HumanB
{
private:
    std::string name;
    Weapon* weapon;
public:
    HumanB(const std::string& n);
    ~ HumanB();
    void setWeapon(Weapon& w);
    void attack() const;
};

#endif
