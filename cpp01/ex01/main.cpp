#include "Zombie.hpp"


int main(void)
{
    Zombie *h = zombieHorde(15,"aaaa");
    for(int i = 0; i < 15; i++)
    {
        std::cout << i << " ";
        h[i].announce();
    }
    delete []h;
}