/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:02:33 by revieira          #+#    #+#             */
/*   Updated: 2023/12/08 17:42:46 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int	main(void)
{
	int		array_int[5] = {1, 2, 3, 4, 5};
	float	array_float[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string		array_string[5] = {"one", "two", "third", "four", "five"};
	
	std::cout << "Array int " << std::endl;
	::iter(array_int, 5, ::print);
	std::cout << std::endl;

	std::cout << "Array float " << std::endl;
	::iter(array_float, 5, ::print);
	std::cout << std::endl;

	std::cout << "Array string " << std::endl;
	::iter(array_string, 5, ::print);
	std::cout << std::endl;
}
