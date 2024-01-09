/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:31:56 by revieira          #+#    #+#             */
/*   Updated: 2024/01/09 15:52:22 by revieira         ###   ########.fr       */
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
static bool	isPseudoLiterals(std::string parameter)
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
	if (!isdigit(parameter[i]))
		return (false);
	if (atof(parameter.c_str()) < std::numeric_limits<int>::min() || atof(parameter.c_str()) > std::numeric_limits<int>::max())
		return (false);
	return (true);
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
	if (!(parameter[i] == 'f' && isdigit(parameter[i - 1])))
		return (false);
	if (std::abs(atof(parameter.c_str())) < std::numeric_limits<float>::min() || std::abs(atof(parameter.c_str())) > std::numeric_limits<float>::max())
		return (false);
	return (true);
}

static bool	isDouble(std::string parameter)
{
	int	i = 0;

	if (parameter[i] == '-' || parameter[i] == '+')
		i++;
	while (isdigit(parameter[i]))
		i++;
	if (!(parameter[i] == '.' && isdigit(parameter[i + 1])))
		return (false);
	if (std::abs(atof(parameter.c_str())) < std::numeric_limits<double>::min() || std::abs(atof(parameter.c_str())) > std::numeric_limits<double>::max())
		return (false);
	return (true);
}

static int	getType(std::string parameter)
{
	if (isPseudoLiterals(parameter))
		return (PSEUDOLITERALS);
	else if (isChar(parameter))
		return (CHAR);
	else if (isFloat(parameter))
		return (FLOAT);
	else if (isDouble(parameter))
		return (DOUBLE);
	else if (isInt(parameter))
		return (INT);
	else
		return(-1);
}

void	ScalarConverter::convert(std::string parameter)
{
	switch (getType(parameter)) {
		case CHAR:
			printChar(parameter);
			break ;
		case INT:
			printInt(parameter);
			break ;
		case FLOAT:
			printFloat(parameter);
			break ;
		case DOUBLE:
			printDouble(parameter);
			break ;
		case PSEUDOLITERALS:
			printPseudoLiterals(parameter);
			break ;
		default:
			printImpossible();
			break ;
	}
}
