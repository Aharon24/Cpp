#include "replace.hpp"


int main(int argc, char *argv[])
{
    std::string filename;
    std::string s1;
    std::string s2;

    if (argc != 4)
    {
        std::cout << "Error\n" << "wrong count argument\n";
        std::cerr << "Usage: ./replace <filename> <s1> <s2>\n";
        return (1);
    }
    filename = argv[1];
    s1 = argv[2];
    s2 = argv[3];
    Replace R(filename, s1 ,s2);
    R.ft_replace();
}