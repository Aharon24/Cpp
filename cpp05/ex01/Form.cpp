#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form(const std::string& name, int gradeToSign, int gradeToExecute): 
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

Form::Form(const Form& other)
:   name(other.name),
    isSigned(other.isSigned),
    gradeToSign(other.gradeToSign),
    gradeToExecute(other.gradeToExecute)
{

}
Form& Form::operator=(const Form& other)
{
    if (this == &other)
        return *this;

    this->isSigned = other.isSigned;

    return *this;
}

Form::~Form()
{

}

const std::string Form::getName() const
{
    return (name);
}

bool Form::getIsSigned() const
{
    return (isSigned);
}

int Form::getGradeToSign() const
{
    return (gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (gradeToExecute);
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{    
    out << form.getName()
        << ", signed: " << form.getIsSigned()
        << ", gradeToSign: " << form.getGradeToSign()
        << ", gradeToExecute: " << form.getGradeToExecute();

    return out;

}