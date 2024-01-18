/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:07:17 by revieira          #+#    #+#             */
/*   Updated: 2024/01/18 14:56:20 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

static Span	randSpan(size_t size, int range, int seed)
{
	srand(seed);
	Span span(size);

	for (size_t i = 0; i < size; i++)
		span.addNumber(rand() % range);
	return (span);
}

int	main(void)
{
	{
		std::cout << "TEST 1 (SUBJECT TEST)" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2 (RANGE OF ITERATORS)" << std::endl;
		std::vector<int>	test;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);

		Span	a(5);
		a.addRange(test.begin(), test.end());
		std::cout << a << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3 (ERROR HANDLING)" << std::endl;
		Span	a(5);
		std::cout << "Create a empty Span" << std::endl;

		std::cout << a << std::endl;
		std::cout << std::endl;
		try {
			std::cout << "Trying to call member function shortestSpan without any number stored" << std::endl;
			a.shortestSpan();
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
		try {
			std::cout << "Trying to call member function longestSpan without any number stored" << std::endl;
			a.longestSpan();
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Adding the maximum size of numbers + 1" << std::endl;
		for (int i = 0; i < 6; i++)
		{
			try {
				a.addNumber(i);
			} catch (std::exception & e) {
				std::cerr << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
		std::cout << a << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 4 (SHORTEST SPAN AND LONGEST SPAN)" << std::endl;

		Span	a = randSpan(5, 100, 0);
		Span	b = randSpan(5, 100, 42);
		Span	c = randSpan(5, 100, 100);

		std::cout << a << std::endl;
		std::cout << "shortest Span: " << a.shortestSpan() << std::endl;
		std::cout << "longest Span: " << a.longestSpan() << std::endl;
		std::cout << std::endl;
		std::cout << b << std::endl;
		std::cout << "shortest Span: " << b.shortestSpan() << std::endl;
		std::cout << "longest Span: " << b.longestSpan() << std::endl;
		std::cout << std::endl;
		std::cout << c << std::endl;
		std::cout << "shortest Span: " << c.shortestSpan() << std::endl;
		std::cout << "longest Span: " << c.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 5 (RANDOM)" << std::endl;

		Span	a = randSpan(5,  100, time(NULL));
		Span	b = randSpan(50, 10000, time(NULL) * 10);

		std::cout << a << std::endl;
		std::cout << "shortest Span: " << a.shortestSpan() << std::endl;
		std::cout << "longest Span: " << a.longestSpan() << std::endl;
		std::cout << std::endl;
		std::cout << b << std::endl;
		std::cout << "shortest Span: " << b.shortestSpan() << std::endl;
		std::cout << "longest Span: " << b.longestSpan() << std::endl;
		// Span	c = randSpan(10000, 1000000000, time(NULL) * 42);
		// std::cout << std::endl;
		// std::cout << c << std::endl;
		// std::cout << "shortest Span: " << c.shortestSpan() << std::endl;
		// std::cout << "longest Span: " << c.longestSpan() << std::endl;
	}
	return (0);
}
