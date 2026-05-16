#include "Functions.hpp"
#include <ctime>
#include <iostream>

int main() {
    srand(time(NULL));

    std::cout << "--- Testing Identification ---" << std::endl;
    
    for (int i = 0; i < 5; i++) {
        std::cout << "Test " << i + 1 << ":" << std::endl;
        
        Base* instance = generate();
        
        std::cout << "  Identify by pointer:   ";
        identify(instance);
        
        std::cout << "  Identify by reference: ";
        identify(*instance);
        
        delete instance;
    }

    return 0;
}