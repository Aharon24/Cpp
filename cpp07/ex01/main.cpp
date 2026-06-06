#include "iter.hpp"
#include <string>

template<typename T>
void print(const T& value)
{
    std::cout << value << std::endl;
}

template<typename T>
void increment(T& value)
{
    value++;
}

template<typename T>
void addExclamation(T& value)
{
    value += "!";
}

int main()
{
    std::cout << "----- INT ARRAY -----" << std::endl;

    int numbers[] = {1, 2, 3, 4};

    iter(numbers, 4, print<int>);

    iter(numbers, 4, increment<int>);

    std::cout << "After increment:" << std::endl;

    iter(numbers, 4, print<int>);

    std::cout << std::endl;


    std::cout << "----- STRING ARRAY -----" << std::endl;

    std::string words[] = {"hello", "world", "cpp"};

    iter(words, 3, print<std::string>);

    iter(words, 3, addExclamation<std::string>);

    std::cout << "After modification:" << std::endl;

    iter(words, 3, print<std::string>);

    std::cout << std::endl;


    std::cout << "----- CONST ARRAY -----" << std::endl;

    const int constArr[] = {10, 20, 30};

    iter(constArr, 3, print<int>);

    return 0;
}

// int main()
// {
//     std::cout << "----- NON-CONST ARRAY -----" << std::endl;

//     int arr[] = {1, 2, 3, 4};

//     iter(arr, 4, print<int>);
//     iter(arr, 4, increment<int>);

//     std::cout << "After increment:" << std::endl;
//     iter(arr, 4, print<int>);

//     std::cout << std::endl;

//     std::cout << "----- CONST ARRAY -----" << std::endl;

//     const int cArr[] = {10, 20, 30};

//     iter(cArr, 3, print<int>); // OK


//     return 0;
// }