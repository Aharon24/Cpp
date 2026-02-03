#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    currentIndex = 0;
    totalContacts = 0;
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
    return (1);
    //else if ()
}

void PhoneBook::ft_set_contact()
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    while (true)
    {
        std::cout << "Write first Name\n";
        if(!getline(std::cin, firstName))
            break ;
        if (ft_chesk_data(firstName, 1))
            break ;
        else
            std::cout <<"wrong try agen\n";
    }
    while (true)
    {
        std::cout << "Write lastName \n";
        if(!getline(std::cin, lastName))
            break ;
        if (ft_chesk_data(lastName, 1))
            break ;
        else
            std::cout <<"wrong try agen\n";
    }
    std::cout << "Write nick name\n";
    if (!getline(std::cin, nickname))
        return ;
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
    contacts[currentIndex].setContact(firstName, lastName, nickname, phoneNumber);
    currentIndex = (currentIndex + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
}