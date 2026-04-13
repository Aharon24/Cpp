
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Form
{
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
public:
    Form();
    ~Form();
    const std::string getname() const;
    bool getisSigned() const;
    int getgradeToSign() const;
    int getgradeToExecute() const;
};




#endif