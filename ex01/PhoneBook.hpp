#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <stdlib.h>


class PhoneBook
{
    private:
        Contact contacts[8];
        int     currentIndex;
        int     totalContacts;
    public:
        PhoneBook();
        void            ft_print_book_member(void);
        void            ft_print_contacts(void);
        void            ft_get_search(int &i);
        void            ft_set_contact(int &i);
        void            ft_set_data(std::string data, int type);
        void            ft_print_index(int n);
        void            ft_search(int &i);
        void            ft_print_corect(int n);
        void            ft_print_taype(std::string data, int tp);
        int             ft_chesk_data(std::string data, int type);
        int             ft_chesk_name(const std::string& data);
        int             ft_chesk_number(std::string data);
        int             ft_get_total_count(void);
        int             ft_chesk_phone_number(std::string data);
        std::string     ft_darkest_secret(int &i);
        std::string     ft_name(int &i);
        std::string     ft_lastname(int &i);
        std::string     ft_nick(int &i);
        std::string     ft_phone(int &i);
};

