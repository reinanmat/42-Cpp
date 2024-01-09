/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:12:55 by revieira          #+#    #+#             */
/*   Updated: 2024/01/09 17:31:21 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	{
		std::cout << "TEST 1" << std::endl;
		int	values[3] = {1, 2, 3};

		Array<int> a(3);
		for (int i = 0; i < 3; i++)
			a[i] = values[i];
		Array<int> b(a);
		Array<int> c;

		c = a;
		std::cout << "Array A:" << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << a[i] << std::endl;
		std::cout << "Array B (COPY CONSTRUCTOR):" << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << b[i] << std::endl;
		std::cout << "Array C (OVERLOADING OPERATOR =):" << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << c[i] << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2" << std::endl;

		Array<std::string>	array(5);

		for (int i = 0; i < 5; i++)
			array[i] = "abc";
		for (int i = 0; i < 5; i++)
			std::cout << array[i] << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3 (INVALID INDEX)" << std::endl;

		Array<float>	array(5);
		try {
			for (int i = 0; i < 10; i++)
			{
				array[i] = i;
				std::cout << array[i] << std::endl;
			}
		} catch (...) {
			std::cout << "Index out of range" << std::endl;
		}
	}
	return (0);
}
