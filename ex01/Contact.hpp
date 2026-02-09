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
    std::string darkest_secret;

public:
    void setContact(const std::string &fName, const std::string &lName,
                    const std::string &nick, const std::string &phone ,std::string &darkest_secret
                );
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getdarkest_secret() const;
};
#endif
