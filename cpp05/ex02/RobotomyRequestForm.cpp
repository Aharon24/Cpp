#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), target(other.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "🔊 drilling noises..." << std::endl;

    std::srand(std::time(NULL));

    if (std::rand() % 2)
    {
        std::cout << target
                  << " has been robotomized successfully 🤖"
                  << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed on " << target << std::endl;
    }
}


RobotomyRequestForm::~RobotomyRequestForm()
{
    
}
