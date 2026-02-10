#include "PhoneBook.hpp"

int ft_chesk(int i, char **argv)
{
	if (i != 1)
	{
		std::cout<< "Error\n";
		std::cout<< "wrong after program name -> " << argv[1] << "\n";
		return (1);
	}
	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	return (0);
}


int main(int argc, char *argv[])
{
	std::string	command;
	PhoneBook	book;
	int			i;

	i = 0;
	if (ft_chesk(argc, argv) == 1)
		return (1);
	while(1)
	{
		if (i != -1)
			std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break ;
		if (command == "ADD")
			book.ft_set_contact(i);
		else if (command == "SEARCH")
			book.ft_get_search(i);
		else if (command == "EXIT")
		{
			std::cout << "Goodbye!\n";
			return (1);
		}
	}
}
