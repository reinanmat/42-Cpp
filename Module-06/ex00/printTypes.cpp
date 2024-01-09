/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printTypes.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:04:48 by revieira          #+#    #+#             */
/*   Updated: 2024/01/09 16:08:58 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	printImpossible(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void	printPseudoLiterals(std::string str)
{
	std::cout << "char : impossible" << std::endl;
	if (str == "nan" || str == "nanf")
	{
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : nanf" << std::endl;
		std::cout << "double : nan" << std::endl;
	}
	else if (str == "inf" || str == "+inf" || str == "-inf")
	{
		std::cout << "int : " << str << std::endl;
		std::cout << "float : " << str << "f" << std::endl;
		std::cout << "double : " << str << std::endl;
	}
	else
	{
		std::cout << "int : " << str.erase(str.length() - 1) << std::endl;
		std::cout << "float : " << str << std::endl;
		std::cout << "double : " << str.erase(str.length() - 1) << std::endl;
	}
}

void printChar(std::string str)
{
	char	converted = str[0];

	if (converted < 0 || converted < std::numeric_limits<char>::min() || converted > std::numeric_limits<char>::max())
		std::cout << "char : impossible" << std::endl;
	else if (!std::isprint(converted))
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : \'" << static_cast<char>(converted) << "\'" << std::endl;
	std::cout << "int : " << static_cast<int>(converted) << std::endl;
	std::cout << "float : " << static_cast<float>(converted) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<double>(converted) << ".0" << std::endl;
}

void printInt(std::string str)
{
	int	converted = atoi(str.c_str());

	if (converted < 0 || converted < std::numeric_limits<char>::min() || converted > std::numeric_limits<char>::max())
		std::cout << "char : impossible" << std::endl;
	else if (!std::isprint(converted))
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : \'" << static_cast<char>(converted) << "\'" << std::endl;
	std::cout << "int : " << static_cast<int>(converted) << std::endl;
	std::cout << "float : " << static_cast<float>(converted) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<double>(converted) << ".0" << std::endl;
}

static int	countDecimalPlaces(std::string num)
{
	int		count = 0;
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

void	printFloat(std::string str)
{
	float	converted = atof(str.c_str());
	int		wholePart = converted;
	int		decimalPlaces = countDecimalPlaces(str);

	if (wholePart < 0 || wholePart < std::numeric_limits<char>::min() || wholePart > std::numeric_limits<char>::max())
		std::cout << "char : impossible" << std::endl;
	else if  (!std::isprint(wholePart))
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : \'" << static_cast<char>(wholePart) << "\'" << std::endl;
	std::cout << "int : " << static_cast<int>(converted) << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(decimalPlaces) << static_cast<float>(converted) << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(decimalPlaces) << static_cast<double>(converted) << std::endl;
}

void	printDouble(std::string str)
{
	double	converted = atof(str.c_str());
	int		wholePart = converted;
	int		decimalPlaces = countDecimalPlaces(str);

	if (wholePart < 0 || wholePart < std::numeric_limits<char>::min() || wholePart > std::numeric_limits<char>::max())
		std::cout << "char : impossible" << std::endl;
	else if  (!std::isprint(wholePart))
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : \'" << static_cast<char>(wholePart) << "\'" << std::endl;
	std::cout << "int : " << static_cast<int>(converted) << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(decimalPlaces) << static_cast<float>(converted) << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(decimalPlaces) << static_cast<double>(converted) << std::endl;
}
