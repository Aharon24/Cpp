#include "Zombie.hpp"


int main(void)
{
    Zombie *h = zombieHorde(10,"aaaa");
    for(int i = 0; i < 10; i++)
    {
        std::cout << i << " ";
        h[i].announce();
    }
    delete []h;
}