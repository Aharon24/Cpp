#include "Intern.hpp"


Intern::Intern()
{
    std::cout << "Intern created" << std::endl;
}


AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    for (int i = 0; i < 3; i++)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;

            switch (i)
            {
                case 0:
                    return new ShrubberyCreationForm(target);
                case 1:
                    return new RobotomyRequestForm(target);
                case 2:
                    return new PresidentialPardonForm(target);
            }
        }
    }

    std::cout << "Intern cannot create " << formName << std::endl;
    return NULL;
}

Intern::~Intern()
{
    std::cout << "destructor" << std::endl;
}