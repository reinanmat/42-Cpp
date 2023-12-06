/*************************************************************************** */
/* kdjwkajdkawjdkwajdkwajg@l                                                                           */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:37:25 by revieira          #+#    #+#             */
/*   Updated: 2023/12/06 15:10:40 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <limits>

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
static void printInt(std::string parameter)
{
	double	converter;

	converter = atof(parameter.c_str());
	if (converter < std::numeric_limits<int>::min() || converter > std::numeric_limits<int>::max())
		std::cout << "char : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(converter) << std::endl;
}

static void printChar(std::string parameter)
{
	int	converter;

	converter = std::atoi(parameter.c_str());
	if (converter < std::numeric_limits<char>::min() || converter > std::numeric_limits<char>::max())
		std::cout << "char : impossible" << std::endl;
	else if  (converter >= 0 && converter <= 32)
		std::cout << "char : not display" << std::endl;
	else
		std::cout << "char : \'" << static_cast<char>(converter) << "\'" << std::endl;
}

static void	printFloat(std::string parameter)
{
	double converter;
	
	converter = atof(parameter.c_str());
	if (converter < std::numeric_limits<float>::min() || converter > std::numeric_limits<float>::max())
		std::cout << "float : impossible" << std::endl;
	else
		std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(converter) << "f" << std::endl;
}

static void	printDouble(std::string parameter)
{
	double	converter;

	converter = atof(parameter.c_str());
	if (converter < std::numeric_limits<double>::min() || converter > std::numeric_limits<double>::max())
		std::cout << "double : impossible" << std::endl;
	else
		std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(converter) << std::endl;
}

void	ScalarConverter::convert(std::string parameter)
{
	printChar(parameter);
	printInt(parameter);
	printFloat(parameter);
	printDouble(parameter);
}
