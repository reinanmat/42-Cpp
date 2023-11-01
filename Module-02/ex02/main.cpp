/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:55:59 by revieira          #+#    #+#             */
/*   Updated: 2023/11/01 15:55:46 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	{
		std::cout << "TEST 1" << std::endl;
		Fixed	a;
		Fixed	b( Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max(a, b) << std::endl;
	}
	{
		std::cout << "TEST 2" << std::endl;
		Fixed a(0);
		Fixed b(0);
		if (a == b)
			std::cout << a << " is equal to " << b << std::endl;

		a = Fixed(1);
		b = Fixed(1.3f);
		if (a != b)
			std::cout << a << " is different to " << b << std::endl;

		a = Fixed(256);
		b = Fixed(1);
		if (a > b)
			std::cout << a << " is greater to " << b << std::endl;

		a = Fixed(1);
		b = Fixed(256);
		if (a < b)
			std::cout << a << " is less than " << b << std::endl;

		a = Fixed(42.25f);
		b = Fixed(0);
		if (a >= b)
			std::cout << a << " is greater than or equal to " << b << std::endl;

		a = Fixed(0);
		b = Fixed(42.25f);
		if (a <= b)
			std::cout << a << " is less than or equal to " << b << std::endl;
	}
	return (0);
}
