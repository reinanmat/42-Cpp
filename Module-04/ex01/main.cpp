/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:59 by revieira          #+#    #+#             */
/*   Updated: 2023/11/29 18:12:44 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	{
		std::cout << "TEST 1" << std::endl;

		std::cout << "Constructors:" << std::endl;
		const Animal *i = new Dog();
		const Animal *j = new Cat();
		std::cout << std::endl;

		i->makeSound();
		j->makeSound();

		std::cout << std::endl;
		std::cout << "Destructors:" << std::endl;
		delete	i;
		delete	j;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2 (COPY ASSIGNMENT OPERATOR)" << std::endl;

		std::cout << "Constructors:" << std::endl;
		Dog	dog1;
		Dog	dog2;
		std::cout << std::endl;

		for (int i = 0; i < 10; i += 2)
		{
			dog1.setIdeaOfBrain(i, "one idea");
			dog1.setIdeaOfBrain(i + 1, "other idea");
		}
		std::cout << "Dog 1 -> Brain:" << std::endl;
		for (int i = 0; i < 10; i++)
			std::cout << dog1.getIdeaOfBrain(i) << std::endl;
		std::cout << "Dog 2 -> Brain:" << std::endl;
		for (int i = 0; i < 10; i++)
			std::cout << dog2.getIdeaOfBrain(i) << std::endl;
		dog2 = dog1;
		std::cout << "Dog 2 -> Brain:" << std::endl;
		for (int i = 0; i < 10; i++)
			std::cout << dog2.getIdeaOfBrain(i) << std::endl;

		std::cout << std::endl;
		std::cout << "Destructors:" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3 (ARRAY OF ANIMALS)" << std::endl;

		std::cout << "Constructors:" << std::endl;
		const int	amountOfAnimals = 6;
		Animal		*animals[amountOfAnimals];
		for (int i = 0; i < amountOfAnimals/2; i++)
			animals[i] = new Dog();
		for (int i = amountOfAnimals/2; i < amountOfAnimals; i++)
			animals[i] = new Cat();

		std::cout << std::endl;
		for (int i = 0; i < amountOfAnimals; i++)
			animals[i]->makeSound();
		
		std::cout << std::endl;
		std::cout << "Destructors:" << std::endl;
		for (int i = 0; i < amountOfAnimals; i++)
			delete animals[i];
	}
	return (0);
}
