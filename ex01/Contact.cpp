#include "PhoneBook.hpp"

void Contact::setContact(const std::string &fName, const std::string &lName,
                    const std::string &nick, const std::string &phone
                )
{
    firstName = fName;
    lastName = lName;
    nickname = nick;
    phoneNumber = phone;
}

std::string Contact::getFirstName() const
{
    return (firstName);
}
std::string Contact::getLastName() const
{
    return (lastName);
}
std::string Contact::getNickname() const
{
    return (nickname);
}

std::string Contact::getPhoneNumber() const
{
    return (phoneNumber);
}