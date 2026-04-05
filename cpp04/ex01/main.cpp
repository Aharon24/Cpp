#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    // --- ТЕСТ 1: ИЗ ЗАДАНИЯ (Массив животных) ---
    std::cout << "===== TEST 1: ARRAY OF ANIMALS =====" << std::endl;
    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size; i++) {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- Deleting animals ---" << std::endl;
    for (int i = 0; i < size; i++) {
        delete animals[i]; // Здесь должны вызываться деструкторы Dog/Cat -> Brain -> Animal
    }


    // --- ТЕСТ 2: ГЛУБОКОЕ КОПИРОВАНИЕ (Deep Copy) ---
    std::cout << "\n===== TEST 2: DEEP COPY (DOG) =====" << std::endl;
    Dog basic;
    basic.setIdea(0, "I want a bone");
    
    std::cout << "Creating 'tmp' as a copy of 'basic'..." << std::endl;
    Dog tmp = basic; // Вызов конструктора копирования
    
    std::cout << "Basic idea 0: " << basic.getIdea(0) << std::endl;
    std::cout << "Tmp idea 0:   " << tmp.getIdea(0) << std::endl;

    std::cout << "\nChanging Tmp's idea..." << std::endl;
    tmp.setIdea(0, "I want to play");

    std::cout << "Basic idea 0 (should stay the same): " << basic.getIdea(0) << std::endl;
    std::cout << "Tmp idea 0 (should be changed):     " << tmp.getIdea(0) << std::endl;


    // --- ТЕСТ 3: ОПЕРАТОР ПРИСВАИВАНИЯ ---
    std::cout << "\n===== TEST 3: ASSIGNMENT OPERATOR =====" << std::endl;
    Cat cat1;
    cat1.setIdea(0, "Catch a bird");
    
    Cat cat2;
    cat2 = cat1; // Вызов оператора присваивания
    
    std::cout << "Cat1 idea 0: " << cat1.getIdea(0) << std::endl;
    std::cout << "Cat2 idea 0: " << cat2.getIdea(0) << std::endl;
    
    return 0;
}