#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Wrong count"<< std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
	return (0);
}


// int main()
// {
//     std::string tests[] =
//     {
//         "a",
//         "A",
//         "z",
//         "0",
//         "9",
//         " ",
//         "!",
//         "@",
//         "#",
//         "$",
//         "42",
//         "-42",
//         "42.0f",
//         "42.0",
//         "0",
//         "-0",
//         "31",
//         "32",
//         "127",
//         "128",
//         "-1",
//         "999",
//         "nan",
//         "nanf",
//         "+inf",
//         "-inf",
//         "+inff",
//         "-inff"
//     };

//     int size = sizeof(tests) / sizeof(tests[0]);

//     for (int i = 0; i < size; i++)
//     {
//         std::cout << "========================" << std::endl;
//         std::cout << "INPUT: " << tests[i] << std::endl;
//         ScalarConverter::convert(tests[i]);
//     }

//     return 0;
// }