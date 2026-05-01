#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL)); // IMPORTANT for Robotomy

    try
    {
        std::cout << "\n===== BUREAUCRATS =====\n";
        Bureaucrat boss("Boss", 1);
        Bureaucrat mid("Mid", 70);
        Bureaucrat intern("Intern", 150);

        std::cout << boss << std::endl;
        std::cout << mid << std::endl;
        std::cout << intern << std::endl;

        std::cout << "\n===== FORMS =====\n";

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Arthur");

        std::cout << shrub << std::endl;
        std::cout << robo << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "\n===== SIGN TEST =====\n";

        intern.signForm(shrub);
        mid.signForm(shrub);

        mid.signForm(robo);
        boss.signForm(robo);

        boss.signForm(pardon);

        std::cout << "\n===== EXECUTE TEST =====\n";

        intern.executeForm(shrub); // fail
        mid.executeForm(shrub);    // ok

        mid.executeForm(robo);     // maybe fail sign/grade
        boss.executeForm(robo);    // ok random

        boss.executeForm(pardon);  // ok

        std::cout << "\n===== DONE =====\n";
    }
    catch (std::exception& e)
    {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
}