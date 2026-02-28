#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "[ DEBUG ]\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n\n";
}
void Harl::info( void )
{ 
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon costs more money. You didn/’t put"
       <<"enough bacon in my burger! If you did, I wouldn/’t be asking for more!\n\n";
}
void Harl::warning( void )
{
    std::cout << "[  WARNING ]\n";
    std::cout <<  "I think I deserve to have some extra bacon for free.\n" 
    << "I/’ve been coming for years, whereas you started working here just last month.\n\n";
}
void Harl::error( void )
{
    std::cout << "[  ERROR ]\n";
    std::cout <<  "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
    
}

void  Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*functions[4])() ={
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            return;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::start(char *str)
{   
    std::string level_name = str;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int lvl;

    lvl = 5;
    for (int i = 0; i < 4; i++)
    {
        if (level_name == levels[i])
        {
            lvl = i;
            break ;
        }
    }
    switch (lvl)
    {
        case 0: this->complain("DEBUG"); /* fall through */
        case 1: this->complain("INFO");  /* fall through */
        case 2: this->complain("WARNING"); /* fall through */
        case 3: this->complain("ERROR"); break;
        default: this->complain("UNKNOWN"); break;
    }


}

Harl::Harl()
{
}

Harl::~Harl()
{
}