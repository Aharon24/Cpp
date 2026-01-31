#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;

public:
    void setContact(const std::string &fName, const std::string &lName,
                    const std::string &nick, const std::string &phone
                );
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
};

#endif
