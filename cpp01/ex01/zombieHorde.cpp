#include "Zombie.hpp"

bool ft_chesk(std::string name)
{
    for(size_t i = 0; i < name.length(); i++)
    {
        if (!std::isspace(name[i]))
            return (false);
    }
    return (true);
}

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return NULL;

    if (name.empty() || ft_chesk(name))
        name = "Unnamed";
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++)
        horde[i] = Zombie(name);

    return horde;
}