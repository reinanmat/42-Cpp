/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:55:59 by revieira          #+#    #+#             */
/*   Updated: 2023/10/06 16:04:29 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void	test(void)
{
	if (Fixed(0) == Fixed(0))
		std::cout << "equal" << std::endl;
	if (Fixed(3.14f) == Fixed(3.14f))
		std::cout << "equal" << std::endl;
	if (Fixed(3.15f) != Fixed(3.14f))
		std::cout << "different" << std::endl;
	if (Fixed(3.15f) > Fixed(3.14f))
		std::cout << "bigger" << std::endl;
	if (Fixed(1) < Fixed(3))
		std::cout << "smaller" << std::endl;
	if (Fixed(1) < Fixed(3))
		std::cout << "smaller" << std::endl;
	if (Fixed(0.5f) <= Fixed(0.5f))
		std::cout << "smaller or equal" << std::endl;
	if (Fixed(1.2f) >= Fixed(1.2f))
		std::cout << "bigger or equal" << std::endl;
}

int	main(void)
{
	Fixed	a;
	Fixed	b( Fixed(5.05f) * Fixed(2));
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	return (0);
}
