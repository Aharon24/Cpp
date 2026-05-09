#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}
bool isInt(const std::string &s)
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
    std::cout << "Detected type: "<< s <<" "<< type << std::endl;
}



ScalarConverter::~ScalarConverter()
{

}