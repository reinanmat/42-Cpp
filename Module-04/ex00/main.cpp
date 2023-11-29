/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:59 by revieira          #+#    #+#             */
/*   Updated: 2023/11/29 15:59:15 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int	main(void)
{
	{
		std::cout << "TEST 1 (SUBJECT-TEST)" << std::endl;
		const Animal	*meta = new Animal();
		const Animal	*j = new Dog();
		const Animal	*i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();	

		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2 (ANIMAL-AND-WRONG-ANIMAL-TEST)" << std::endl;
		std::cout << "-ANIMAL:" << std::endl;
		std::cout << "Constructors:" << std::endl;
		Animal	*base;
		Cat		derived1;
		Dog		derived2;
		std::cout << std::endl;

		derived1.makeSound();
		base = &derived1;
		base->makeSound();

		derived2.makeSound();
		base = &derived2;
		base->makeSound();

		std::cout << std::endl;

		std::cout << "-WRONG ANIMAL:" << std::endl;
		std::cout << "Constructors:" << std::endl;
		WrongAnimal	*wrongBase;
		WrongCat	wrongDerived;
		std::cout << std::endl;

		wrongBase = &wrongDerived;
		wrongBase->makeSound();
		wrongDerived.makeSound();

		std::cout << std::endl;
		std::cout << "Destructors:" << std::endl;
	}
	return (0);
}
