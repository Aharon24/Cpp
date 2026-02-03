#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    currentIndex = 0;
    totalContacts = 0;
}

std::string PhoneBook::ft_name()
{
    std::string firstName;
    while (true)
    {
        std::cout << "Write first Name\n";
        if(!getline(std::cin, firstName))
            break ;
        if (ft_chesk_data(firstName, 1))
            return (firstName);
        else
            std::cout <<"wrong try agen\n";
    }
    return (firstName);
}

std::string PhoneBook::ft_lastname()
{
    std::string lastName;
    while (true)
    {
        std::cout << "Write lastName \n";
        if(!getline(std::cin, lastName))
            break ;
        if (ft_chesk_data(lastName, 1))
            return (lastName);
        else
            std::cout <<"wrong try agen\n";
    }
    return (lastName);
}
std::string PhoneBook::ft_nick()
{
    std::string nickname;
    std::cout << "Write nick name\n";
    if (!getline(std::cin, nickname))
        return (nickname);
    return (nickname);
}
std::string PhoneBook::ft_phone()
{
    std::string phoneNumber;
    while (true)
    {
        std::cout << "Write phone number \n";
        std::cout << "exemple 098 78 78 78 \n";
        if (!getline(std::cin, phoneNumber))
            break ;
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


int PhoneBook::ft_chesk_data(std::string data, int type)
{
    if (type == 1)
    {
        if (ft_chesk_name(data))
            return(1);
        else
            return (0);
    }
    // if (type == 2)
    // {

    // }
    return (1);
}

void PhoneBook::ft_print_contacts(void)
{
    for(int i = 0; i < totalContacts; i++)
    {
        std::cout << contacts[i].getFirstName() << "  " << contacts[i].getLastName() << "  " ;
        std::cout << contacts[i].getNickname() << "  "  << contacts[i].getPhoneNumber() << std::endl;
    }
}

void PhoneBook::ft_set_contact()
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
   
    firstName = ft_name();
    lastName = ft_lastname();
    nickname = ft_nick();
    phoneNumber = ft_phone();
    contacts[currentIndex].setContact(firstName, lastName, nickname, phoneNumber);
    currentIndex = (currentIndex + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
    ft_print_contacts();
}

void PhoneBook::ft_get_search(void)
{
    
}