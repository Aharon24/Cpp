

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#include <iostream>
#include <string>

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
		static void convert(const std::string& literal);
};


#endif