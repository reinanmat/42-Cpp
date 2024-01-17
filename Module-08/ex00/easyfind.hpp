/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:27:23 by revieira          #+#    #+#             */
/*   Updated: 2024/01/17 15:36:25 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <algorithm>
#include <iterator>

template <typename T>
void	easyfind(const T &container, int find)
{
	typename T::const_iterator	it;
	std::cout << "Element: " << find << "\t->\t";
	it = std::find(container.begin(), container.end(), find);
	if (it != container.end())
	{
		int index = std::distance(container.begin(), it);
		std::cout << "found in the index: " << index << std::endl;
	}
	else
		throw std::runtime_error("Error: element not found");
}
