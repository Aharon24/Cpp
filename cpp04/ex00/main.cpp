#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
//     std::cout << "--- CREATING META ---" << std::endl;
//     const Animal* meta = new Animal();
    
//     std::cout << "--- CREATING DOG ---" << std::endl;
//     const Animal* j = new Dog();
    
//     std::cout << "--- CREATING CAT ---" << std::endl;
//     const Animal* i = new Cat();

//     std::cout << "--- TESTING TYPES ---" << std::endl;
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;

//     std::cout << "--- TESTING SOUNDS ---" << std::endl;
//     i->makeSound();
//     j->makeSound();
//     meta->makeSound();

//     std::cout << "--- DELETING ---" << std::endl;
//     delete meta;
//     delete j;
//     delete i;

//     return 0;
// }

// #include "WrongAnimal.hpp"
// #include "WrongCat.hpp"
// #include <iostream>

// int main()
// {
//     std::cout << "--- 1. CREATING WRONG OBJECTS ---" << std::endl;
//     const WrongAnimal* meta = new WrongAnimal();
//     const WrongAnimal* cat = new WrongCat();

//     std::cout << std::endl;
//     std::cout << "Meta type: " << meta->getType() << std::endl;
//     std::cout << "Cat type: " << cat->getType() << std::endl;

//     std::cout << std::endl;
    
//     std::cout << "--- 2. SOUND CHECK (POLYMORPHISM ERROR) ---" << std::endl;
    
//     std::cout << "WrongAnimal sound: ";
//     meta->makeSound(); 
    
//     std::cout << "WrongCat sound via WrongAnimal* pointer: \n";

//     cat->makeSound(); 
    
//     std::cout << std::endl;
//     std::cout << "--- 3. DESTRUCTION CHECK (DESTRUCTOR ERROR) ---" << std::endl;
    
//     std::cout << "Deleting meta:" << std::endl;
//     delete meta;
    
//     std::cout << "\nDeleting cat via WrongAnimal* pointer:" << std::endl;

//     delete cat; 

//     std::cout << "\n--- 4. DIRECT CALL (FOR COMPARISON) ---" << std::endl;
//     const WrongCat* directCat = new WrongCat();
//     directCat->makeSound(); 
    
//     std::cout << "Deleting directCat:" << std::endl;
//     delete directCat; 

//     return 0;
// }

int main()
{
    std::cout << "--- 1. TESTING CORRECT POLYMORPHISM (Animal/Dog/Cat) ---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "Dog type: " << j->getType() << std::endl;
    std::cout << "Cat type: " << i->getType() << std::endl;

    std::cout << "Cat sound: ";
    i->makeSound();
    std::cout << "Dog sound: ";
    j->makeSound();
    std::cout << "Animal sound: ";
    meta->makeSound();

    std::cout << "\n--- 2. DELETING CORRECT OBJECTS ---" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << "\n------------------------------------------------------\n" << std::endl;

    std::cout << "--- 3. TESTING WRONG POLYMORPHISM (WrongAnimal/WrongCat) ---" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;

    std::cout << "WrongAnimal sound: ";
    wrongMeta->makeSound();

    std::cout << "WrongCat sound via WrongAnimal* pointer: ";

    wrongCat->makeSound(); 

    std::cout << "\n--- 4. TESTING WRONG DESTRUCTION ---" << std::endl;
    std::cout << "Deleting wrongMeta:" << std::endl;
    delete wrongMeta;

    std::cout << "\nDeleting wrongCat via WrongAnimal* pointer:" << std::endl;

    delete wrongCat; 

    std::cout << "\n--- 5. DIRECT CALL (FOR COMPARISON) ---" << std::endl;
    const WrongCat* directCat = new WrongCat();
    std::cout << "Sound via WrongCat* pointer: ";
    directCat->makeSound(); 
    delete directCat;

    return 0;
}