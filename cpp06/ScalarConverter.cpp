#include "ScalarConverter.hpp"
#include <string>
#include <string>
ScalarConverter::ScalarConverter()
{

}

static bool IsDouble(std::string s)
{
	bool dot;
	bool digit;
	size_t i;

	i = 0;
	dot = false;
	digit = false;
	if (s == "nan" || s == "+inf" || s == "-inf")
			return (true);
	if (s.empty())
		return (false);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while(i < s.length())
	{
		if(s[i] == '.')
		{
			if(dot)
				return (false);
			else
				dot = true;
		}
		else if(std::isdigit(s[i]))
			digit = (true);
		else
			return (false);
		i++;
	}
	return (digit);
}

static bool IsFloat(const std::string &s)
{
	bool dot = false;
	bool digit = false;
	size_t i = 0;
	if (s == "nanf" || s == "+inff" || s == "-inff")
			return (true);
	if (s.empty() || s[s.length() - 1] != 'f')
		return (false);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (i < s.length() - 1)
	{
		if(s[i] == '.')
		{
			if(dot)
				return (false);
			else
				dot = true;
		}
		else if(std::isdigit(s[i]))
			digit = (true);
		else
			return (false);
		i++;
	}
	return (dot && digit);
}

static bool isInt(const std::string &s)
{
	size_t i = 0;
	if (s.empty())
		return false;
	if (s[0] == '+' || s[0] == '-')
		i++;
	if(i == s.length())
		return false;
	
	while (i < s.length())
	{
		if (std::isdigit(s[i]))
			i++;
		else
			return false;
	}
	return true;
}

static Type detectType(const std::string &literal)
{
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return CHAR;
	else if(isInt(literal))
		return INT;
	else if (IsFloat(literal))
		return (FLOAT);
	else if (IsDouble(literal))
		return (DOUBLE);
	return UNKNOWN;
}

void ScalarConverter::convert(const std::string &literal)
{
	std::string s;
	std::cout << "Input: " << literal << std::endl;
    Type type = detectType(literal);
	if (type == 0)
		s = "Char";
	if (type == 1)
		s = "INT";
	if (type == 2)
		s = "FLOAT";
	if (type == 3)
		s = "DOUBLE";
    std::cout << "Detected type: "<< s <<" "<< type << std::endl;
}

ScalarConverter::~ScalarConverter()
{

}