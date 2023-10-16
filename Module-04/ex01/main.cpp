/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:59 by revieira          #+#    #+#             */
/*   Updated: 2023/10/16 17:34:27 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define MAX_ANIMALS 6

int	main(void)
{
	/* { */
	/* 	const Animal *i = new Dog(); */
	/* 	const Animal *j = new Cat(); */

	/* 	delete	i; */
	/* 	delete	j; */
	/* } */
	{
		Brain	b1;
		Brain	b2;

		for (int i = 0; i < 50; i++)
		{
			b1.setIdea(i, "one idea");
			b1.setIdea(i + 50, "other idea");
		}

		b2 = b1;

		for (int i = 0; i < 100; i++)
			std::cout << b2.getIdea(i) << std::endl;

		
	}
	/* { */
	/* 	Animal	*animals[MAX_ANIMALS]; */

	/* 	for (int i = 0; i < MAX_ANIMALS/2; i++) */
	/* 	{ */
	/* 		animals[i] = new Dog(); */
	/* 		animals[i + MAX_ANIMALS/2] = new Cat(); */
	/* 	} */
	/* 	for (int i = 0; i < MAX_ANIMALS; i++) */
	/* 		animals[i]->makeSound(); */

	/* 	for (int i = 0; i < MAX_ANIMALS; i++) */
	/* 		delete animals[i]; */
	/* } */
	return (0);
}
