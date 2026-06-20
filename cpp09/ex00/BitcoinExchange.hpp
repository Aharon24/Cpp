#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>


class BitcoinExchange
{
private:
   std::map<std::string, double> _database;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other); 
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void loadDatabase(const std::string &filename);
    void convert_for_map(const std::string &line);
    void print_data( void );
    bool ft_data_check(std::string data_n);
    void processInput(const std::string &filename);
    void ft_input_work(std::string &line);
    std::string trim(const std::string &s);
    bool ft_value_check(std::string value);
    void calculate(std::string data, std::string value);
};


#endif