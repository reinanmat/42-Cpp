/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:31:56 by revieira          #+#    #+#             */
/*   Updated: 2024/01/08 14:37:25 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* CONSTRUCTORS AND DESTRUTORS */
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	(void)obj;
}

ScalarConverter::~ScalarConverter() {}

/* OPERATORS OVERLOADING */
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

/* MEMBERS FUNCTIONS */
static bool	checkPseudoLiterals(std::string parameter)
{
	std::string pseudoLiterals[]= {
		"inf",
		"+inf",
		"-inf",
		"inff",
		"+inff",
		"-inff",
		"nan",
		"nanf"
	};

	for (int i = 0; i < 8 ; i++)
		if (pseudoLiterals[i] == parameter)	
			return (true);
	return (false);
}

static bool	isInt(std::string parameter)
{
	int i = 0;

	if (parameter[i] == '-' || parameter[i] == '+')
		i++;
	if (isdigit(parameter[i]))
		return (true);
	return (false);
}

static bool isChar(std::string parameter)
{
	if (parameter.size() > 1 && (parameter[0] == '-' || parameter[0] == '+') && isdigit(parameter[1]))
		return (false);
	if (isascii(parameter[0]) && !isdigit(parameter[0]))
		return (true);
	return (false);
}

static bool	isFloat(std::string parameter)
{
	int	i = 0;

	if (parameter[i] == '-' || parameter[i] == '+')
		i++;
	while (isdigit(parameter[i]))
		i++;
	if (parameter[i] == '.')
		i++;
	while (isdigit(parameter[i]))
		i++;
	if (parameter[i] == 'f' && isdigit(parameter[i - 1]))
		return (true);
	return (false);
}

static bool	isDouble(std::string parameter)
{
	int	i = 0;

	if (parameter[i] == '-' || parameter[i] == '+')
		i++;
	while (isdigit(parameter[i]))
		i++;
	if (parameter[i] == '.' && isdigit(parameter[i + 1]))
		return (true);
	return (false);
}

static int	getType(std::string parameter)
{
	if (checkPseudoLiterals(parameter))
		return (0);
	else if (isChar(parameter))
		return (1);
	else if (isFloat(parameter))
		return (3);
	else if (isDouble(parameter))
		return (4);
	else if (isInt(parameter))
		return (2);
	else
		return(-1);
}

void	ScalarConverter::convert(std::string parameter)
{
	switch (getType(parameter)) {
		case 0:
			printPseudoLiterals(parameter);
			break ;
		case 1:
			printChar(parameter);
			break ;
		case 2:
			printInt(parameter);
			break ;
		case 3:
			printFloat(parameter);
			break ;
		case 4:
			printDouble(parameter);
			break ;
		default:
			std::cerr << "Error: unexpected error" << std::endl;
			break ;
	}
}
