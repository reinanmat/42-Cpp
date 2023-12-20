/*************************************************************************** */
/* kdjwkajdkawjdkwajdkwajg@l                                                                           */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:37:25 by revieira          #+#    #+#             */
/*   Updated: 2023/12/20 17:01:44 by revieira         ###   ########.fr       */
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
static int	countDecimalPlaces(std::string num)
{
	int	count = 0;
	size_t	found;

	found = num.find(".");
	if (found == std::string::npos)
		return (1);
	for (size_t i = found + 1; i < num.size(); i++)
	{
		if (isdigit(num[i]))
			count++;
		else
			break ;
	}
	return (count);
}

static void	printPseudoLiterals(std::string parameter)
{
	std::cout << "char : impossible" << std::endl;
	if (parameter == "inf" || parameter == "+inf" || parameter == "-inf")
		std::cout << "int : " << parameter << std::endl;
	else
		std::cout << "int : impossible" << std::endl;

	if (parameter == "inf" || parameter == "+inf" || parameter == "-inf")
		std::cout << "float : " << parameter << "f" << std::endl;
	else
		std::cout << "float : " << parameter << std::endl;

	if (parameter == "inff" || parameter == "+inff" || parameter == "-inff")
		std::cout << "double : " << parameter.erase(parameter.length() - 1) << std::endl;
	else
		std::cout << "double : " << parameter << std::endl;
}

static void printInt(std::string parameter)
{
	double	converter;

	converter = atof(parameter.c_str());

	if (converter < std::numeric_limits<char>::min() || converter > std::numeric_limits<char>::max())
		std::cout << "char : impossible" << std::endl;
	else if  (converter >= 0 && converter <= 32)
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : \'" << static_cast<char>(converter) << "\'" << std::endl;

	if (converter < std::numeric_limits<int>::min() || converter > std::numeric_limits<int>::max())
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(converter) << std::endl;

	std::cout << "float : " << static_cast<int>(converter) << ".0f" << std::endl;

	std::cout << "double : " << static_cast<int>(converter) << ".0" << std::endl;
}

static void printChar(std::string parameter)
{
	int	converter;

	converter = parameter[0];
	if (converter < std::numeric_limits<char>::min() || converter > std::numeric_limits<char>::max())
		std::cout << "char : impossible" << std::endl;
	else if  (converter >= 0 && converter <= 32)
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : \'" << static_cast<char>(converter) << "\'" << std::endl;

	if (converter < std::numeric_limits<int>::min() || converter > std::numeric_limits<int>::max())
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(converter) << std::endl;

	std::cout << "float : " << static_cast<int>(converter) << ".0f" << std::endl;

	std::cout << "double : " << static_cast<int>(converter) << ".0" << std::endl;
}

static void	printFloat(std::string parameter)
{
	int		wholePart;
	int		decimalPlaces;
	double	converter;
	
	converter = atof(parameter.c_str());
	wholePart = converter;
	decimalPlaces = countDecimalPlaces(parameter);

	if (wholePart < std::numeric_limits<char>::min() || wholePart > std::numeric_limits<char>::max())
		std::cout << "char : impossible" << std::endl;
	else if  (wholePart >= 0 && wholePart <= 32)
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : \'" << static_cast<char>(wholePart) << "\'" << std::endl;

	if (converter < std::numeric_limits<int>::min() || converter > std::numeric_limits<int>::max())
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(converter) << std::endl;

	if (parameter != "0" && (std::abs(converter) < std::numeric_limits<float>::min() || std::abs(converter) > std::numeric_limits<float>::max()))
		std::cout << "float : impossible" << std::endl;
	else
		std::cout << "float : " << std::fixed << std::setprecision(decimalPlaces) << static_cast<float>(converter) << "f" << std::endl;

	if (parameter != "0" && (std::abs(converter) < std::numeric_limits<double>::min() || std::abs(converter) > std::numeric_limits<double>::max()))
		std::cout << "double : impossible" << std::endl;
	else
		std::cout << "double : " << std::fixed << std::setprecision(decimalPlaces) << static_cast<double>(converter) << std::endl;
}

static void	printDouble(std::string parameter)
{
	int		wholePart;
	int		decimalPlaces;
	double	converter;

	converter = atof(parameter.c_str());
	wholePart = converter;
	decimalPlaces = countDecimalPlaces(parameter);

	if (wholePart < std::numeric_limits<char>::min() || wholePart > std::numeric_limits<char>::max())
		std::cout << "char : impossible" << std::endl;
	else if  (wholePart >= 0 && wholePart <= 32)
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : \'" << static_cast<char>(wholePart) << "\'" << std::endl;

	if (converter < std::numeric_limits<int>::min() || converter > std::numeric_limits<int>::max())
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(converter) << std::endl;

	if (parameter != "0" && (std::abs(converter) < std::numeric_limits<float>::min() || std::abs(converter) > std::numeric_limits<float>::max()))
		std::cout << "float : impossible" << std::endl;
	else
		std::cout << "float : " << std::fixed << std::setprecision(decimalPlaces) << static_cast<float>(converter) << "f" << std::endl;

	if (parameter != "0" && (std::abs(converter) < std::numeric_limits<double>::min() || std::abs(converter) > std::numeric_limits<double>::max()))
		std::cout << "double : impossible" << std::endl;
	else
		std::cout << "double : " << std::fixed << std::setprecision(decimalPlaces) << static_cast<double>(converter) << std::endl;
}

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
	int	i = 0;
	
	if (parameter[i] == '-' || parameter[i] == '+')
		i++;
	if (isascii(parameter[i]) && !isdigit(parameter[i]))
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
			std::cout << "Pseudo Literals" << std::endl;
			printPseudoLiterals(parameter);
			break ;
		case 1:
			std::cout << "Char" << std::endl;
			printChar(parameter);
			break ;
		case 2:
			std::cout << "Int" << std::endl;
			printInt(parameter);
			break ;
		case 3:
			std::cout << "Float" << std::endl;
			printFloat(parameter);
			break ;
		case 4:
			std::cout << "Double" << std::endl;
			printDouble(parameter);
			break ;
		default:
			std::cerr << "Error" << std::endl;
			break ;
	}
}
