#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cctype>

class PhoneBook
{
    private:
        Contact contacts[8];
        int     currentIndex;
        int     totalContacts;
    public:
        PhoneBook();
        void            ft_print_contacts(void);
        void            ft_get_search(void);
        void            ft_set_contact();
        void            ft_set_data(std::string data, int type);
        int             ft_chesk_data(std::string data, int type);
        int             ft_chesk_name(const std::string& data);
        std::string     ft_name();
        std::string     ft_lastname();
        std::string     ft_nick();
        std::string     ft_phone();
};

