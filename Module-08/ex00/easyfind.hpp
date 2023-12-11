/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:27:23 by revieira          #+#    #+#             */
/*   Updated: 2023/12/11 18:34:06 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

#include <iostream>
#include <algorithm>

template <typename T>
void	easyfind(T array, int find)
{
	if (std::find(array.begin(), array.end(), find) == array.end())
		std::cout << RED "Not Found " << find << RESET << std::endl;
	else
		std::cout << GRN "Found " << find << RESET << std::endl;
}
