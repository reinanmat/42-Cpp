/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:36:46 by revieira          #+#    #+#             */
/*   Updated: 2024/01/17 18:00:02 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <cstdlib>
#include <vector>
#include <list>
#include <deque>

int	main(void)
{
	{
		std::cout << "TEST 1 (VECTOR)" << std::endl;
		std::vector<int>	n;
		n.push_back(1);
		n.push_back(0);
		n.push_back(5);
		n.push_back(7);
		n.push_back(10);
		std::cout << "Numbers in Cointaner:	[";
		for (std::vector<int>::iterator it = n.begin(); it != n.end(); it++)
			std::cout << *it << (it != (n.end() - 1) ? ", " : "]");
		std::cout << std::endl;
		try {
			easyfind(n, 1);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			easyfind(n, 0);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			easyfind(n, 10);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			easyfind(n, -1);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			easyfind(n, -42);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			easyfind(n, 11);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2 (LIST)" << std::endl;
		std::list<int>	n;
		std::cout << "Numbers in Cointaner:	[";
		for (int i = 0; i <= 42; i++) {
			n.push_back(i);
			std::cout << i << (i != 42 ? ", " : "]");
		}
		std::cout << std::endl;
		try {
			easyfind(n, 0);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			easyfind(n, 10);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			easyfind(n, 42);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			easyfind(n, -1);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3 (RANDOM DEQUE)" << std::endl;
		srand(time(NULL));
		std::deque<int>	n;
		int	size = 5;
		std::cout << "Numbers in Cointaner:	[";
		for (int i = 0; i < size; i++)
		{
			int number = rand() % 10 + 1;
			n.push_back(number);
			std::cout << number << (i != size - 1 ? ", " : "]");
		}
		std::cout << std::endl;
		try {
			easyfind(n, rand() % 10 + 1);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			easyfind(n, rand() % 10 + 1);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			easyfind(n, rand() % 10 + 1);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			easyfind(n, rand() % 10 + 1);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
