/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:58:53 by revieira          #+#    #+#             */
/*   Updated: 2023/12/08 17:26:07 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void	iter(const T array[], size_t size, void f(const T))
{
	for (size_t i = 0; i < size; i++)
	  f(array[i]);
}

template <typename T>
void	print(const T x)
{
	std::cout << x << std::endl;
}
