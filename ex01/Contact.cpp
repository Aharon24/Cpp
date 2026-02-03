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