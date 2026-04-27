#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    std::cout << "=== VALID CREATION ===" << std::endl;
    try
    {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;

        a.incrementGrade();
        std::cout << "After increment: " << a << std::endl;

        a.decrementGrade();
        std::cout << "After decrement: " << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST HIGH BOUND ===" << std::endl;
    try
    {
        Bureaucrat b("Bob", 1);
        std::cout << b << std::endl;

        b.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST LOW BOUND ===" << std::endl;
    try
    {
        Bureaucrat c("Charlie", 150);
        std::cout << c << std::endl;

        c.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST INVALID CONSTRUCTOR ===" << std::endl;
    try
    {
        Bureaucrat d("Dave", 0); 
    }
    catch (std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat e("Eve", 200);
    }
    catch (std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    std::cout << "\n=== FORM TEST ===" << std::endl;

    try
    {
        Bureaucrat bob("Bob", 50);
        Form form("FormA", 40, 30);

        std::cout << form << std::endl;

        bob.signForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}