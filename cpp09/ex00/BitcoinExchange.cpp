#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}


BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if(this == &other)
        return *this;
    _database = other._database;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}

bool BitcoinExchange::ft_value_check(std::string value)
{
    char *end;  
    double v;

    v = std::strtod(value.c_str(), &end);
    if (end == value.c_str() || *end != '\0')
    {
        std::cerr << "Error: bad input => " << value << std::endl;
        return (false);
    }
    if (v < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (v > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return (true);
}

bool BitcoinExchange::ft_data_check(std::string data_n)
{
    int m;
    int d;

    if ((data_n[4] != '-' || data_n[7] != '-') || data_n.size() != 10)
    {
        // std::cout << "wrong" <<  data_n << "\n";
        return false;
    }
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(data_n[i])))
        {
            // std::cout << "wrong" <<  data_n << "\n";
            return false;
        }
    }
    m = std::atoi(data_n.substr(5, 2).c_str());
    d = std::atoi(data_n.substr(8, 2).c_str());
    if ((d < 1 || d > 31) || (m < 1 || m > 12))
    {
        // std::cout << "wrong" <<  data_n << "\n";
        return false;
    }
    // std::cout << data_n << "\n";
    return true;
}

void BitcoinExchange::convert_for_map(const std::string &line)
{
    std::string data;
    std::string data_n;
    char *end;
    double data_d;
    size_t pos;

    end = NULL;
    pos = line.find(',');

    if (pos == std::string::npos)
        return;
    data = line.substr(0, pos);
    data_n = line.substr(pos + 1);
    if (data.empty() || data_n.empty())
        return;
    if(!ft_data_check(data))
        return ;
    data_d = std::strtod(data_n.c_str(), &end);
    if (end == data_n.c_str() || *end != '\0')
        return;
    if (data_d < 0)
        return ;
    
    _database[data] = data_d;

}
void BitcoinExchange::calculate(std::string data, std::string value)
{
    double v;
    std::map<std::string, double>::iterator it;

    v = std::atof(value.c_str());
    it = _database.lower_bound(data);

}


void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::string line;

    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::getline(file, line);
    while (std::getline(file, line))
    {
        convert_for_map(line);
    }
}

std::string BitcoinExchange::trim(const std::string &s)
{
    size_t start;
    size_t end;

    start = s.find_first_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";
    end = s.find_last_not_of(" \t\n\r");
    return s.substr(start, end - start + 1);
}

void BitcoinExchange::ft_input_work(std::string &line)
{
    size_t pos;
    std::string data;
    std::string value;

    pos = line.find('|');
    if (pos == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return ;
    }
    data = line.substr(0, pos);
    value = line.substr(pos + 1);
    data = trim(data);
    value = trim(value);
    // std::cout << data << "\n";
    // std::cout << value << "\n"; 
    if (!ft_data_check(data))
        return;
    if (!ft_value_check(value))
        return ;
    calculate(data, value);
    // std::cout << data << " => " << value << "\n";
}

void BitcoinExchange::processInput(const std::string &filename)
{
    std::string line;
    int c;

    c = 0;
    std::ifstream file(filename.c_str());
    if (!file.is_open())    
    {
        std::cerr << "Error: could not open input file ." << std::endl;
        return ;
    }
    if (!std::getline(file, line))
        return;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        ft_input_work(line);
    }

}


void BitcoinExchange::print_data()
{

    for (std::map<std::string, double>::iterator it = _database.begin();
     it != _database.end();
     ++it)
    {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}