#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook
{

    private:
        Contact contacts[8]; // массив из 8 контактов
        int currentIndex;    // индекс для нового контакта
        int totalContacts;
};

