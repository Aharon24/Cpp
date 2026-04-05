#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "===== 1. TESTING ABSTRACTION =====" << std::endl;

    std::cout << "AAnimal is abstract. Creating concrete animals..." << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << "\n===== 2. TESTING SOUNDS =====" << std::endl;
    std::cout << j->getType() << " says: ";
    j->makeSound();
    std::cout << i->getType() << " says: ";
    i->makeSound();

    std::cout << "\n===== 3. TESTING DEEP COPY (Optional check) =====" << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
    } 

    std::cout << "\n===== 4. DELETING POLYMORPHIC OBJECTS =====" << std::endl;
    delete j;  
    delete i;  

    // AAnimal test; 
    // AAnimal* testPtr = new AAnimal();

    return 0;
}