#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cctype>

class PhoneBook
{
    private:
        Contact contacts[8]; // массив из 8 контактов
        int currentIndex;    // индекс для нового контакта
        int totalContacts;
    public:
        void ft_set_contact();
        int ft_chesk_data(std::string data, int type);
        void ft_set_data(std::string data, int type);
        int ft_chesk_name(const std::string& data);
};

