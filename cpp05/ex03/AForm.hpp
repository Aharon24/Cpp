
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>


class Bureaucrat;

class AForm
{

private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
public:
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();


    //get
    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;


    void execute(Bureaucrat const & executor) const;
    virtual void executeAction() const = 0;
    //main logic
    void beSigned(const Bureaucrat& b);

        // Exceptions
    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    
};
std::ostream& operator<<(std::ostream& out, const AForm& form);




#endif