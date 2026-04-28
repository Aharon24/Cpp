#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);

        ShrubberyCreationForm form("home");

        std::cout << form << std::endl;

        intern.signForm(form);   // или boss.signForm(form)

        boss.executeForm(form);

    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}