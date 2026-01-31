#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook
{
    private:
        int ft_chesk_number(std::string number);
        int ft_chesk_name(std::string name);
    private:
        Contact contacts[8]; // массив из 8 контактов
        int currentIndex;    // индекс для нового контакта
        int totalContacts;
    public:
        void ft_set_contact();
};

