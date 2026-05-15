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


void ScalarConverter::ft_convert(Type type, const std::string &conv)
{
	double d;
	float f;

	d = 0;
	f = 0.0;
	if (type == CHAR)
		d = static_cast<double>(conv[0]);
	else if (type == INT)
		d = static_cast<double>(std::atoi(conv.c_str()));
	else if (type == FLOAT)
	{
		f = static_cast<float>(std::strtod(conv.c_str(), NULL));
		d = static_cast<double>(f);
	}
	else if (type == DOUBLE)
		d = std::strtod(conv.c_str(), NULL);
	else 
		return ;
	ScalarConverter::printChar(d);
    ScalarConverter::printInt(d);
    ScalarConverter::printFloat(d);
    ScalarConverter::printDouble(d);
}

void ScalarConverter::convert(const std::string &literal)
{
    Type type = detectType(literal);

	if (type == UNKNOWN)
	{
    	std::cout << "Invalid literal" << std::endl;
    	return;
	}
	ft_convert(type,literal);
}



void ScalarConverter::printChar(double d)
{
    char c;
    std::cout << "char: ";
    if (d < 0 || d > 127)
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (std::isnan(d) || std::isinf(d))
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    c = static_cast<char>(d);
    if (!std::isprint(c))
    {
        std::cout << "Non displayable" << std::endl;
        return;
    }
    std::cout << "'" << c << "'" << std::endl;
}
void ScalarConverter::printInt(double d)
{
    int v;

    v = 0;
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d))
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    v = static_cast<int>(d);
    std::cout << v << std::endl;
}

void ScalarConverter::printFloat(double d)
{
    float f;

    f = 0;
    std::cout << "float: ";
    if (std::isnan(d))
    {
        std::cout << "nanf" << std::endl;
        return;
    }
    if (std::isinf(d))
    {
        if (d > 0)
            std::cout << "+inff" << std::endl;
        else
            std::cout << "-inff" << std::endl;
        return;
    }
    if (d < -std::numeric_limits<float>::max()
        || d > std::numeric_limits<float>::max())
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    f = static_cast<float>(d);
    if (f == static_cast<int>(f))
        std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    else
        std::cout << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
    std::cout << "double: ";
    if (std::isnan(d))
    {
        std::cout << "nan" << std::endl;
        return;
    }
    if (std::isinf(d))
    {
        if (d > 0)
            std::cout << "+inf" << std::endl;
        else
            std::cout << "-inf" << std::endl;
        return;
    }
    std::cout << std::fixed << std::setprecision(1)
              << d << std::endl;
}


ScalarConverter::~ScalarConverter()
{

}