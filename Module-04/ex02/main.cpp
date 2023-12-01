/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:59 by revieira          #+#    #+#             */
/*   Updated: 2023/12/01 13:54:27 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		prevTests();
	}
	std::cout << std::endl;
	{
		std::cout << "FINAL TEST" << std::endl;
		std::cout << "Constructors:" << std::endl;
		Dog dog;
		Cat cat;
		AAnimal *a = &dog;
		AAnimal *b = &cat;
		std::cout << std::endl;
		
		a->makeSound();
		b->makeSound();

		std::cout << std::endl;
		std::cout << "Destructors" << std::endl;
	}
	return (0);
}
