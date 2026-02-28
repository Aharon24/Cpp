#include "Harl.hpp"

int main(int argc, char *argv[])
{
    Harl harl;

    if (argc != 2)
    {
        std::cout << "wrong argument\n";
        return (1);
    }
    harl.start(argv[1]);
    
    return 0;
}