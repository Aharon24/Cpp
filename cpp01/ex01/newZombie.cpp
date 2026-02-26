#include "Zombie.hpp"


Zombie* newZombie( std::string name )
{
    Zombie *z;

    z = new Zombie(name);
    return (z);
}

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0)
        return nullptr;
    
    Zombie *Horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        Horde[i] = Zombie(name);
    }
    return Horde;
}
