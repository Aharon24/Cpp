

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <limits>
#include <iomanip>


enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN
};

class ScalarConverter
{
    private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
		
	public:
		static void ft_convert(Type type, const std::string &conv);
		static void convert(const std::string& literal);
		static  void printInt(double d);
    	static  void printFloat(double d);
		static  void printChar(double d);
    	static  void printDouble(double d);
};


#endif