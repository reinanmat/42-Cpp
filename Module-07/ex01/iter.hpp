/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:58:53 by revieira          #+#    #+#             */
/*   Updated: 2024/01/11 16:03:49 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void	iter(T *array, unsigned int size, void f(T&))
{
	if (array)
		for (size_t i = 0; i < size; i++)
			f(array[i]);
}

template <typename T>
void	print(T &x)
{
	std::cout << x << std::endl;
}
