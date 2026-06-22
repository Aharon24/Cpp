#include "RPN.hpp"


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout<< "Wrong Argumet\n";
        return (1);
    }
        try
    {
        RPN rpn;

        std::cout << rpn.evaluate(argv[1]) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
}


// void run_test(const std::string& input)
// {
//     std::cout << "Input: " << input << std::endl;

//     try
//     {
//         RPN rpn;
//         int result = rpn.evaluate(input);
//         std::cout << "Result: " << result << std::endl;
//     }
//     catch (const std::exception&)
//     {
//         std::cout << "Result: Error" << std::endl;
//     }

//     std::cout << "------------------------" << std::endl;
// }

// int main()
// {
//     std::vector<std::string> tests;

//     // VALID
//     tests.push_back("8 9 * 9 - 9 - 9 - 4 - 1 +");
//     tests.push_back("7 7 * 7 -");
//     tests.push_back("1 2 * 2 / 2 * 2 4 - +");
//     tests.push_back("3 5 +");
//     tests.push_back("9 1 -");
//     tests.push_back("2 3 + 4 *");
//     tests.push_back("0 9 *");

//     // EDGE ERRORS
//     tests.push_back("1 +");
//     tests.push_back("1 2 3 +");
//     tests.push_back("0 0 /");
//     tests.push_back("a b +");
//     tests.push_back("10 2 +");
//     tests.push_back("");
//     tests.push_back("5");

//     for (size_t i = 0; i < tests.size(); i++)
//     {
//         run_test(tests[i]);
//     }

//     return 0;
// }