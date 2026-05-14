#include "ScalarConverter.hpp"


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

static void  ft_conv_char(const std::string &conv)
{
	char  v;
	double d;

	v = conv[0];
	d = static_cast<double>(v);
	ScalarConverter::printChar(d);
    ScalarConverter::printInt(d);
    ScalarConverter::printFloat(d);
    ScalarConverter::printDouble(d);
}

static void  ft_conv_int(const std::string &conv)
{
	int v;
	double d;

	v = std::atoi(conv.c_str());
	d = static_cast<double>(v);
	ScalarConverter::printChar(d);
    ScalarConverter::printInt(d);
    ScalarConverter::printFloat(d);
    ScalarConverter::printDouble(d);
}
static void  ft_conv_float(const std::string &conv)
{
	float v;
	double d;

	v = std::strtof(conv.c_str(), NULL);
	d = static_cast<double>(v);
	ScalarConverter::printChar(d);
    ScalarConverter::printInt(d);
    ScalarConverter::printFloat(d);
    ScalarConverter::printDouble(d);
}
static void  ft_conv_double(const std::string &conv)
{
	int v;
	double d;

	v =  d = std::strtod(conv.c_str(), NULL);
	d = static_cast<double>(v);
	ScalarConverter::printChar(d);
    ScalarConverter::printInt(d);
    ScalarConverter::printFloat(d);
    ScalarConverter::printDouble(d);
}

void ScalarConverter::ft_convert(Type type, const std::string &conv)
{
	if (type == CHAR)
		ft_conv_char(conv);
	else if (type == INT)
		ft_conv_int(conv);
	else if (type == FLOAT)
		ft_conv_float(conv);
	else if (type == DOUBLE)
		ft_conv_double(conv);
	else 
		return ;
}

void ScalarConverter::convert(const std::string &literal)
{
	std::string s;
	std::cout << "Input: " << literal << std::endl;
    Type type = detectType(literal);
	if (type == CHAR)
		s = "Char";
	if (type == INT)
		s = "INT";
	if (type == FLOAT)
		s = "FLOAT";
	if (type == DOUBLE)
		s = "DOUBLE";
	if (type == UNKNOWN)
	{
    	std::cout << "Invalid literal" << std::endl;
    	return;
	}
	ft_convert(type,literal);
    std::cout << "Detected type: "<< s <<" "<< type << std::endl;
}

ScalarConverter::~ScalarConverter()
{

}