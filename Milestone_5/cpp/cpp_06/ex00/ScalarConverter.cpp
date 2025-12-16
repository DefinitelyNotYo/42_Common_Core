/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:04:01 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/05 10:35:39 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}
    
ScalarConverter::ScalarConverter(ScalarConverter &c)
{
	(void) c;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &value)
{
	(void) value;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	
}
	
void ScalarConverter::convert(std::string str)
{
	std::string type;
	if (str == "inf" || str == "+inf" || str == "inff" || str == "+inff")
	{
		std::cout << "char: impossible\n" << "int: impossibile\n"
				  << "float: inff\n" << "double: inf\n";
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible\n" << "int: impossibile\n"
				  << "float: -inff\n" << "double: -inf\n";		
	}
	type = getType(str);
	// std::cout << type << std::endl;
	if (type == "char")
		ScalarConverter::convert_char(str);
	else if (type == "int")
		ScalarConverter::convert_int(str);
	else if (type == "float")
		ScalarConverter::convert_float(str);
	else if (type == "double")
		ScalarConverter::convert_double(str);
	else
	{
		std::cout << "char: impossible\nint: impossible\n"
				  << "float: nanf\ndouble: nan\n";
	}
}

std::string ScalarConverter::getType(std::string str)
{
	int i = -1;
	int count = 0;
	if (str.length() == 1)
	{
		if (str[0] > 47 && str[0] < 58)
			return ("int");
		else
			return ("char");
	}
	while (++i < (int)str.length())
	{
		if (str[i] < 48 || str[i] > 57)
		{
			if (str[i] == '.' && count < 1 && str[i + 1] > 47 && str[i + 1] < 58)
				count++;
			else if (str[i] == 'f' && i == (int)str.length() - 1)
				;
			else if ((str[i] == '-' && i == 0) || (str[i] == '+' && i == 0))
				;
			else
				return ("nan");
		}
	}
	if (count == 1 && str[str.length() - 1] == 'f')
		return ("float");
	else if (count == 1)
		return ("double");
	else
		return ("int");
}

void ScalarConverter::convert_char(std::string str)
{
	char c = str[0];
		std::cout << "char: '" << c << "'" << std::endl
			  	  << "int: " << static_cast<int>(c) << std::endl
			  	  << "float: " << static_cast<float>(c) << ".0f" << std::endl
			  	  << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convert_int(std::string str)
{
	errno = 0;
	long long int i = std::strtol(str.c_str(), NULL, 10);
	if (i > INT_MAX || i < INT_MIN || errno == ERANGE)
	{
		std::cout << "char: impossible\n"
			  	  << "int: impossible\n";
		if (i == static_cast<long long int>(static_cast<float>(i)))
			std::cout << "float: " << static_cast<float>(i) << std::endl;
		else
			std::cout << "float: impossible\n";
		if (i == static_cast<long long int>(static_cast<double>(i)))
			std::cout << "double: " << static_cast<double>(i) << std::endl;
		else
			std::cout << "double: impossible\n";
	}
	else
	{
		int n = static_cast<int>(i);
		if (n < 0 || n > 127)
			std::cout << "char: impossible\n";
		else if (n >= 0 && n < 32)
			std::cout << "char: non displayable\n";
		else
			std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
		std::cout << "int: " << n << std::endl;
		std::cout << "float: " << static_cast<float>(n) << ".0f\n";
		std::cout << "double: " << static_cast<double>(n) << ".0\n";
	}
}

void ScalarConverter::convert_float(std::string str)
{
	float f = std::strtof(str.c_str(), NULL);
	std::cout << f << std::endl;
	if (static_cast<int>(f) < 0 || static_cast<int>(f) > 127)
		std::cout << "char: impossible\n";
	else if (static_cast<int>(f) >= 0 && static_cast<int>(f) < 32)
		std::cout << "char: non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;


	if (std::strtol(str.c_str(), NULL, 10) == static_cast<int>(f))
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible\n";


	std::cout << "float: " << f << "f\n";
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convert_double(std::string str)
{
	double d = std::strtod(str.c_str(), NULL);
	std::cout << d << std::endl;
	if (static_cast<int>(d) < 0 || static_cast<int>(d) > 127)
		std::cout << "char: impossible\n";
	else if (static_cast<int>(d) >= 0 && static_cast<int>(d) < 32)
		std::cout << "char: non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;


	if (std::strtol(str.c_str(), NULL, 10) == static_cast<int>(d))
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible\n";


	std::cout << "float: " << static_cast<float>(d) << "f\n";
	std::cout << "double: " << d << std::endl;
}
