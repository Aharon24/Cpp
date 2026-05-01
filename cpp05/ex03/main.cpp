#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
   std::srand(std::time(NULL));

    std::cout << "\n===== BUREAUCRATS =====\n";

    Bureaucrat boss("Boss", 1);
    Bureaucrat mid("Mid", 70);
    Bureaucrat intern("Intern", 150);

    std::cout << boss << std::endl;
    std::cout << mid << std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n===== INTERN FACTORY =====\n";

    Intern someIntern;

    AForm* f1 = someIntern.makeForm("shrubbery creation", "home");
    AForm* f2 = someIntern.makeForm("robotomy request", "Bender");
    AForm* f3 = someIntern.makeForm("presidential pardon", "Arthur");
    AForm* f4 = someIntern.makeForm("unknown form", "test");

    std::cout << "\n===== SIGN PHASE =====\n";

    if (f1)
    {
        intern.signForm(*f1);
        mid.signForm(*f1);
        boss.signForm(*f1);
    }

    if (f2)
    {
        mid.signForm(*f2);
        boss.signForm(*f2);
    }

    if (f3)
    {
        boss.signForm(*f3);
    }

    std::cout << "\n===== EXECUTE PHASE =====\n";

    if (f1)
    {
        intern.executeForm(*f1);
        mid.executeForm(*f1);
        boss.executeForm(*f1);
    }

    if (f2)
    {
        mid.executeForm(*f2);
        boss.executeForm(*f2);
    }

    if (f3)
    {
        boss.executeForm(*f3);
    }

    std::cout << "\n===== CLEANUP =====\n";

    delete f1;
    delete f2;
    delete f3;
    delete f4;

    std::cout << "DONE\n";

    return 0;
}