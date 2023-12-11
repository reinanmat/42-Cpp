/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:36:46 by revieira          #+#    #+#             */
/*   Updated: 2023/12/11 18:42:46 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <map>

int	main(void)
{
	{
		std::cout << "TEST 1 (VECTOR)" << std::endl;
		std::vector<int>	n;
		for (int i = 0; i <= 42; i++)
			n.push_back(i);
		::easyfind(n, 0);
		::easyfind(n, 10);
		::easyfind(n, 42);
		::easyfind(n, -1);
		::easyfind(n, 43);
		::easyfind(n, 100);
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2 (LIST)" << std::endl;
		std::list<int>	n;
		for (int i = 0; i <= 42; i++)
			n.push_back(i);
		::easyfind(n, 0);
		::easyfind(n, 10);
		::easyfind(n, 42);
		::easyfind(n, -1);
		::easyfind(n, 43);
		::easyfind(n, 100);
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3 (MAP)" << std::endl;
		std::list<int>	n;
		for (int i = 0; i <= 42; i++)
			n.push_back(i);
		::easyfind(n, 0);
		::easyfind(n, 10);
		::easyfind(n, 42);
		::easyfind(n, -1);
		::easyfind(n, 43);
		::easyfind(n, 100);
	}
}
