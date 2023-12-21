/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:54:38 by revieira          #+#    #+#             */
/*   Updated: 2023/12/21 15:19:54 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <limits>

class ScalarConverter
{
	public:
		static void	convert(std::string parameter);

	private: 
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter &other);
};

void	printChar(std::string str);
void	printInt(std::string str);
void	printFloat(std::string str);
void	printDouble(std::string str);
void	printPseudoLiterals(std::string str);
