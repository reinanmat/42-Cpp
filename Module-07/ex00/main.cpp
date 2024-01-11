/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:38:17 by revieira          #+#    #+#             */
/*   Updated: 2024/01/11 15:00:41 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int	main(void)
{
	{
		std::cout << "TEST 1 (SUBJECT TEST)" << std::endl;

		int a = 2;
		int b = 3;

		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2" << std::endl;
		
		double a = 0.42;
		double b = 42.42;

		std::cout << "Before Swap:" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;

		std::cout << std::endl;
		::swap(a, b);

		std::cout << "After Swap:" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3" << std::endl;
		
		std::string a = "42sp";
		std::string b = "42fr";

		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min = " << ::min(a, b) << std::endl;
		std::cout << "max = " << ::max(a, b) << std::endl;
	}
	return 0;
}
