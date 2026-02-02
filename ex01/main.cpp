#include "PhoneBook.hpp"

int ft_chesk(int i)
{
	if (i != 1)
	{
		std::cout << "Error wrong argument count\n";
		return (2);
	}
	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	return (0);
}


int main(int argc, char *argv[])
{
	std::string command;
	PhoneBook book;

	if (ft_chesk(argc) == 1)
	{
		std::cout<< "wrong" << argv[1] << "\n";
		return (1);
	}
	while(1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			book.ft_set_contact();
		else if (command == "EXIT")
		{
			std::cout << "Goodbye!\n";
			return (1);
		}
		//else if (command == "SEARCH")
		
	}
}