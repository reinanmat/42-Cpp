/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printTypes.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:04:48 by revieira          #+#    #+#             */
/*   Updated: 2023/12/21 16:47:49 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	printPseudoLiterals(std::string str)
{
	std::cout << "char : impossible" << std::endl;
	if (str == "inf" || str == "+inf" || str == "-inf")
		std::cout << "int : " << str << std::endl;
	else
		std::cout << "int : impossible" << std::endl;
	if (str == "inf" || str == "+inf" || str == "-inf")
		std::cout << "float : " << str << "f" << std::endl;
	else
		std::cout << "float : " << str << std::endl;
	if (str == "inff" || str == "+inff" || str == "-inff")
		std::cout << "double : " << str.erase(str.length() - 1) << std::endl;
	else
		std::cout << "double : " << str << std::endl;
}

void printChar(std::string str)
{
	int	converted = str[0];

	if (converted < std::numeric_limits<char>::min() || converted > std::numeric_limits<char>::max())
		std::cout << "char : impossible" << std::endl;
	else if  (!std::isprint(converted))
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : \'" << static_cast<char>(converted) << "\'" << std::endl;
	std::cout << "int : " << static_cast<int>(converted) << std::endl;
	std::cout << "float : " << static_cast<int>(converted) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<int>(converted) << ".0" << std::endl;
}

void printInt(std::string str)
{
	double	converted = atof(str.c_str());

	if (converted < 0 || converted < std::numeric_limits<char>::min() || converted > std::numeric_limits<char>::max())
		std::cout << "char : impossible" << std::endl;
	else if  (!std::isprint(converted))
		std::cout << "char : Non displayable" << std::endl;
	else
		std::cout << "char : \'" << static_cast<char>(converted) << "\'" << std::endl;
	if (converted < std::numeric_limits<int>::min() || converted > std::numeric_limits<int>::max())
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(converted) << std::endl;
	std::cout << "float : " << static_cast<int>(converted) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<int>(converted) << ".0" << std::endl;
}

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

void	printFloat(std::string str)
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
	if (converted < std::numeric_limits<int>::min() || converted > std::numeric_limits<int>::max())
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(converted) << std::endl;
	if (converted != 0 && (std::abs(converted) < std::numeric_limits<float>::min() || std::abs(converted) > std::numeric_limits<float>::max()))
		std::cout << "float : impossible" << std::endl;
	else
		std::cout << "float : " << std::fixed << std::setprecision(decimalPlaces) << static_cast<float>(converted) << "f" << std::endl;
	if (converted != 0 && (std::abs(converted) < std::numeric_limits<double>::min() || std::abs(converted) > std::numeric_limits<double>::max()))
		std::cout << "double : impossible" << std::endl;
	else
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
	if (converted < std::numeric_limits<int>::min() || converted > std::numeric_limits<int>::max())
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(converted) << std::endl;
	if (converted != 0 && (std::abs(converted) < std::numeric_limits<float>::min() || std::abs(converted) > std::numeric_limits<float>::max()))
		std::cout << "float : impossible" << std::endl;
	else
		std::cout << "float : " << std::fixed << std::setprecision(decimalPlaces) << static_cast<float>(converted) << "f" << std::endl;
	if (converted != 0 && (std::abs(converted) < std::numeric_limits<double>::min() || std::abs(converted) > std::numeric_limits<double>::max()))
		std::cout << "double : impossible" << std::endl;
	else
		std::cout << "double : " << std::fixed << std::setprecision(decimalPlaces) << static_cast<double>(converted) << std::endl;
}
