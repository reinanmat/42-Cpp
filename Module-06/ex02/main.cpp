/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:36:36 by revieira          #+#    #+#             */
/*   Updated: 2024/01/09 17:20:49 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <exception>
#include <iostream>
#include <cstdlib>
#include <ctime>

Base	*generate(void)
{
	srand(time(NULL));
	char	type = 'A' + rand() % 3;
	Base	*base;

	std::cout << "generated " << type << " type class" << std::endl;
	switch (type) {
		case 'A':
			base = new A();
			break ;
		case 'B':
			base = new B();
			break ;
		case 'C':
			base = new C();
			break ;
	}
	return (base);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "The actual type of the object is A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "The actual type of the object is B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "The actual type of the object is C" << std::endl;
}

void	identify(Base &p)
{
	try {
		A a = dynamic_cast<A &>(p);
		std::cout << "The actual type of the object is A" << std::endl;
	} catch (...) {
		try {
			B b = dynamic_cast<B &>(p);
			std::cout << "The actual type of the object is B" << std::endl;
		} catch (...) {
			try {
				C b = dynamic_cast<C &>(p);
				std::cout << "The actual type of the object is C" << std::endl;
			} catch (...) {
				std::cout << "impossible" << std::endl;
			}
		}
	}
}

int	main(void)
{
	{
		std::cout << "TEST 1" << std::endl;

		Base	*ptrA = new A();
		Base	&refA = *ptrA;
		std::cout << "generated A type class" << std::endl;
		Base	*ptrB = new B();
		Base	&refB = *ptrB;
		std::cout << "generated B type class" << std::endl;
		Base	*ptrC = new C();
		Base	&refC = *ptrC;
		std::cout << "generated C type class" << std::endl;

		std::cout << std::endl;

		std::cout << "identify pointers:" << std::endl;
		identify(ptrA);
		identify(ptrB);
		identify(ptrC);

		std::cout << std::endl;

		std::cout << "identify references:" << std::endl;
		identify(refA);
		identify(refB);
		identify(refC);

		delete ptrA;
		delete ptrB;
		delete ptrC;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2 (RANDOM)" << std::endl;

		Base	*ptr = generate();

		std::cout << "identify pointers:" << std::endl;
		identify(ptr);

		std::cout << std::endl;

		std::cout << "identify references:" << std::endl;
		Base	&ref = *ptr;
		identify(ref);
		delete ptr;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3 (INVALID POINTER)" << std::endl;

		Base	*ptr = NULL;
		std::cout << "generated a invalid pointer" << std::endl;

		identify(ptr);
	}
	return (0);
}
