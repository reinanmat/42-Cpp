/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:07:17 by revieira          #+#    #+#             */
/*   Updated: 2023/12/12 17:23:24 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

static Span	randSpan(size_t size, int seed)
{
	srand(seed);
	Span span(size);

	for (size_t i = 0; i < size; i++)
		span.addNumber(rand() % 100);
	return (span);
}

int	main(void)
{
	{
		std::cout << "TEST 1 (SUBJECT)" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2" << std::endl;
		std::vector<int>	test;
		test.push_back(1);
		test.push_back(2);
		test.push_back(3);
		test.push_back(4);
		test.push_back(5);

		Span	a(5);
		a.addNumber(test.begin(), test.end());
		std::cout << a << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3" << std::endl;
		Span	b(5);

		for (int i = 0; i < 6; i++)
		{
			try {
				b.addNumber(i);
			} catch (std::exception & e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 4 RANDOM" << std::endl;

		Span	a = randSpan(10, 0);
		Span	b = randSpan(10, 100);
		Span	c = randSpan(10, 10000);

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
	return (0);
}
