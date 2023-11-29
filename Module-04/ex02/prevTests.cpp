/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prevTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:40:23 by revieira          #+#    #+#             */
/*   Updated: 2023/11/29 18:41:47 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	prevTests(void)
{
	{
		std::cout << "TEST 1 (SUBJECT-TEST)" << std::endl;
		// const AAnimal	*meta = new AAnimal();
		const AAnimal	*j = new Dog();
		const AAnimal	*i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		// meta->makeSound();	

		// delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2 (ANIMAL-AND-WRONG-ANIMAL-TEST)" << std::endl;
		std::cout << "-ANIMAL:" << std::endl;
		std::cout << "Constructors:" << std::endl;
		AAnimal	*base;
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
		{
		std::cout << "TEST 3" << std::endl;

		std::cout << "Constructors:" << std::endl;
		const AAnimal *i = new Dog();
		const AAnimal *j = new Cat();
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
		std::cout << "TEST 4 (COPY ASSIGNMENT OPERATOR)" << std::endl;

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
		std::cout << "TEST 5 (ARRAY OF ANIMALS)" << std::endl;

		std::cout << "Constructors:" << std::endl;
		const int	amountOfAnimals = 6;
		AAnimal		*animals[amountOfAnimals];
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
}
