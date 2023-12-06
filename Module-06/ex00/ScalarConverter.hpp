/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:54:38 by revieira          #+#    #+#             */
/*   Updated: 2023/12/06 14:48:23 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
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
