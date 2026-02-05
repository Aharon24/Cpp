#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    currentIndex = 0;
    totalContacts = 0;
}

std::string PhoneBook::ft_name(int &i)
{
    std::string firstName;
    while (true)
    {
        std::cout << "Write first Name\n";
        if(!getline(std::cin, firstName))
        {
            i = -1;
            break ;
        }
        if (ft_chesk_data(firstName, 1))
            return (firstName);
        else
            std::cout <<"wrong try agen\n";
    }
    return (firstName);
}

std::string PhoneBook::ft_lastname(int &i)
{
    std::string lastName;
    while (true)
    {
        std::cout << "Write lastName \n";
        if(!getline(std::cin, lastName))
        {
            i = -1;
            break ;
        }
        if (ft_chesk_data(lastName, 1))
            return (lastName);
        else
            std::cout <<"wrong try agen\n";
    }
    return (lastName);
}
std::string PhoneBook::ft_nick(int &i)
{
    std::string nickname;
    std::cout << "Write nick name\n";
    if (!getline(std::cin, nickname))
    {
        i = -1;
        return (nickname);
    }
    return (nickname);
}
std::string PhoneBook::ft_phone(int &i)
{
    std::string phoneNumber;
    while (true)
    {
        std::cout << "Write phone number \n";
        std::cout << "exemple 098 78 78 78 \n";
        if (!getline(std::cin, phoneNumber))
        {
            i = -1;
            break ;
        }
        if (ft_chesk_data(phoneNumber, 2))
            break ;
        else
            std::cout <<"wrong try agen\n";
    }
    return (phoneNumber);
}

int PhoneBook::ft_chesk_name(const std::string& data)
{
    for (size_t i = 0; i < data.size(); i++)
    {
        if (!std::isalpha(static_cast<unsigned char>(data[i])))
            return 0;
    }
    return 1;
}

int PhoneBook::ft_chesk_number(std::string data)
{
    int number;

    for(size_t i = 0; i < data.size(); i++)
    {
        if (!std::isdigit(data[i]))
            return (-1);
    }
    number = atoi(data.c_str());
    if (number >= 8)
        return (-1);
    return (number);
}

int PhoneBook::ft_chesk_phone_number(std::string data)
{
    int count_number;

    count_number = 0;
    for(size_t i = 0; i < data.size(); i++)
    {
        if (std::isdigit(data[i]))
            count_number++;
        else if ((data[i] != ' '))
        {
            std::cout << "wrong\n";
            return (0);
        }
    }
    if ( count_number != 9)
    {
        std::cout << "wrong count of number\n";
        return (0);
    }
    return (1);
}

int PhoneBook::ft_chesk_data(std::string data, int type)
{
    int n;
    if (type == 1)
    {
        if (ft_chesk_name(data))
            return(1);
        else
            return (0);
    }
    if (type == 2)
    {
        if (ft_chesk_phone_number(data))
            return (1);
        else
            return (0);
    }
    if (type == 3)
    {
        n = ft_chesk_number(data);
        if ((n && n != -1) || n == 0)
            return (n);
        else
            return (-1);
    }
    return (1);
}

void PhoneBook::ft_print_contacts(void)
{
    for (int i = 0; i < 42; i++)
    {
        std::cout << "-";
    }
    std::cout << "\n";
    for(int i = 0; i < totalContacts; i++)
    {
        std::cout <<"|";
        std::cout << contacts[i].getFirstName() << "|" << contacts[i].getLastName() << "|" ;
        std::cout << contacts[i].getNickname() << "|"  << contacts[i].getPhoneNumber() << "|" << std::endl;
    }
}

void PhoneBook::ft_set_contact(int &i)
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;

    firstName = ft_name(i);
    if (i == -1)
        return ;
    lastName = ft_lastname(i);
    if (i == -1)
        return ;
    nickname = ft_nick(i);
    if (i == -1)
        return ;
    phoneNumber = ft_phone(i);
    if (i == -1)
        return ;
    contacts[currentIndex].setContact(firstName, lastName, nickname, phoneNumber);
    currentIndex = (currentIndex + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
    //ft_print_contacts();
}
int PhoneBook::ft_get_total_count(void)
{
    return (totalContacts);
}

void    PhoneBook::ft_print_taype(std::string data, int tp)
{
    if (tp == 4)
    {
        std::cout << " ";
        for(unsigned long i = 0; i < data.size(); i++)
        {
            if (data[i] != ' ')
                std::cout <<data[i];
        }
        return ;
    }
    if (data.size() == 10)
        std::cout << data;
    else if (data.size() > 10)
    {
        for(int i = 0; i < 10; i++)
        {
            std::cout <<data[i];
        }
        std::cout << ".";
    }
    else if (data.size() < 10)
    {
        for(unsigned long i = 1; i <= (unsigned long)10 - data.size(); i++)
        {
            std::cout << " ";
        }
        std::cout << data;
    }
}

void PhoneBook::ft_print_corect(int n)
{
    std::string data;
    std::cout <<"|";
    data = contacts[n].getFirstName();
    ft_print_taype(data,1);
    std::cout << "|";
    data = contacts[n].getLastName();
    ft_print_taype(data,1);
    std::cout  << "|" ;
    data = contacts[n].getNickname();
    ft_print_taype(data,1);
    std::cout  << "|";
    data = contacts[n].getPhoneNumber();
    ft_print_taype(data,4);
    std::cout  << "|" << std::endl;
}

void PhoneBook::ft_print_index(int n)
{
    int count;

    count = ft_get_total_count();
    if (n < count)
        ft_print_corect(n);
    else
        std::cout << "wrong index\n";
}

void   PhoneBook::ft_search(int &i)
{
    std::string index;
    int         n;
    while (true)
    {
        std::cout << "Write index\n";
        if(!getline(std::cin, index))
        {
            i = -1;
            break ;
        }
        n = ft_chesk_data(index, 3);
        if((n  && n != -1) || n == 0)
        {
           ft_print_index(n);
           break;
        }
        else
            std::cout <<"wrong try agen\n";
    }
}

void PhoneBook::ft_get_search(int &i)
{
    ft_search(i);
}