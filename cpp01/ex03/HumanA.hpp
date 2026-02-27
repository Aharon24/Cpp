#include "Weapon.hpp"

class  HumanA
{
private:
    std::string name;
    Weapon& weapon;
public:
    HumanA(const std::string& n, Weapon& w);
    ~HumanA();
    void attack() const;
};