#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>



ShrubberyCreationForm::ShrubberyCreationForm()
{

}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
{

}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    return *this;
}