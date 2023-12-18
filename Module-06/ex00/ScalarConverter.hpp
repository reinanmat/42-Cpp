/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:54:38 by revieira          #+#    #+#             */
/*   Updated: 2023/12/15 15:20:02 by revieira         ###   ########.fr       */
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
		~ScalarConverter();
		ScalarConverter	&operator=(const ScalarConverter &other);
		static void	convert(std::string parameter);

	private: 
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
};
