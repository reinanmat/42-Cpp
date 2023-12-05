/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:37:25 by revieira          #+#    #+#             */
/*   Updated: 2023/12/05 18:47:06 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>

/* CONSTRUCTORS AND DESTRUTORS */
ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	(void)obj;
}

ScalarConverter::~ScalarConverter()
{

}

/* OPERATORS OVERLOADING */
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

/* MEMBERS FUNCTIONS */
static std::string convertInt(std::string parameter)
{
	std::stringstream inter;
	std::string result;
	
	inter << std::atoi(parameter.c_str());
	inter >> result;
	return (result);
}

static char convertChar(std::string parameter)
{
	(void)parameter;
	return (1);
}

static float	convertToFloat(std::string parameter)
{
	(void)parameter;
	return (1);
}

static double	convertToDouble(std::string parameter)
{
	(void)parameter;
	return (1);
}

void	ScalarConverter::convert(std::string parameter)
{
	std::cout << "char:\t" << convertChar(parameter) << std::endl;
	std::cout << "int:\t" << convertInt(parameter) << std::endl;
	std::cout << "float:\t" << convertToFloat(parameter) << std::endl;
	std::cout << "double:\t" << convertToDouble(parameter) << std::endl;
}
