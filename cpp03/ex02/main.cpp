#include "ClapTrap.hpp"

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "--- CONSTRUCTING FRAGTRAP ---" << std::endl;
    FragTrap frag("Fragger");
    
    std::cout << "\n--- TESTING ATTACK (Should be 30 damage) ---" << std::endl;
    // FragTrap использует атаку ClapTrap, но со своим уроном 30
    frag.attack("a training dummy");

    std::cout << "\n--- TESTING STATS (HP 100, Energy 100) ---" << std::endl;
    frag.takeDamage(40);    // Осталось 60 HP
    frag.beRepaired(20);    // Стало 80 HP
    
    // Проверим, что энергии много (было 100, стало 98 после атаки и ремонта)
    std::cout << "FragTrap is still standing!" << std::endl;

    std::cout << "\n--- TESTING SPECIAL ABILITY ---" << std::endl;
    frag.highFivesGuys();

    std::cout << "\n--- TESTING COPY & ASSIGNMENT ---" << std::endl;
    FragTrap fragCopy(frag);
    FragTrap fragAssign;
    fragAssign = frag;
    fragAssign.highFivesGuys();

    std::cout << "\n--- DESTRUCTING ALL ---" << std::endl;
    // Здесь мы увидим правильный порядок удаления для всех 3 объектов
    return 0;
}