#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute): 
name(name),
isSigned(false),
gradeToSign(gradeToSign),
gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
:   name(other.name),
    isSigned(other.isSigned),
    gradeToSign(other.gradeToSign),
    gradeToExecute(other.gradeToExecute)
{

}
AForm& AForm::operator=(const AForm& other)
{
    if (this == &other)
        return *this;

    this->isSigned = other.isSigned;

    return *this;
}

AForm::~AForm()
{

}

const std::string AForm::getName() const
{
    return (name);
}

bool AForm::getIsSigned() const
{
    return (isSigned);
}

int AForm::getGradeToSign() const
{
    return (gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{    
    out << form.getName()
        << ", signed: " << form.getIsSigned()
        << ", gradeToSign: " << form.getGradeToSign()
        << ", gradeToExecute: " << form.getGradeToExecute();

    return out;

}
const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade too low!";
}

AForm::execute()