/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:59 by revieira          #+#    #+#             */
/*   Updated: 2023/10/16 15:28:57 by revieira         ###   ########.fr       */
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
		std::cout << "\nSUBJECT-TEST" << std::endl;
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
	{
		std::cout << "\nANIMAL-AND-WRONG-ANIMAL-TEST" << std::endl;
		std::cout << "Animal:" << std::endl;
		Animal	*base;
		Cat		derived;

		base = &derived;
		derived.makeSound();
		base->makeSound();
	}
	{
		std::cout << "Wrong Animal:" << std::endl;
		WrongAnimal	*wrongBase;
		WrongCat	wrongDerived;

		wrongBase = &wrongDerived;
		wrongDerived.makeSound();
		wrongBase->makeSound();
	}
	return (0);
}
