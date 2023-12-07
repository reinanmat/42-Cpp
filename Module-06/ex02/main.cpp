/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:36:36 by revieira          #+#    #+#             */
/*   Updated: 2023/12/07 16:32:03 by revieira         ###   ########.fr       */
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
	Base	*ptr = generate();
	identify(ptr);

	Base	&ref = *ptr;
	identify(ref);
	
	delete ptr;
	return (0);
}
