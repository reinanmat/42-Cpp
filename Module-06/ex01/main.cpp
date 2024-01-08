/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:04:41 by revieira          #+#    #+#             */
/*   Updated: 2024/01/08 16:54:34 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <cstdlib>

int	main(void)
{
	{
		std::cout << "TEST 1" << std::endl;
		Data		*ptr = new Data(42);
		uintptr_t	uintPtr;
		Data		*deserializePtr;

		uintPtr = Serializer::serializer(ptr);
		deserializePtr = Serializer::deserialize(uintPtr);

		std::cout << "data ptr original, value:\t" << ptr->getValue() << std::endl;
		std::cout << "data ptr deserialize, value:\t" << deserializePtr->getValue() << std::endl;
		delete	ptr;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2 (RANDOM)" << std::endl;
		srand(time(NULL));
		Data		*ptr = new Data(rand() % 1000);
		uintptr_t	uintPtr;
		Data		*deserializePtr;

		uintPtr = Serializer::serializer(ptr);
		deserializePtr = Serializer::deserialize(uintPtr);

		std::cout << "data ptr original, value:\t" << ptr->getValue() << std::endl;
		std::cout << "data ptr deserialize, value:\t" << deserializePtr->getValue() << std::endl;
		delete	ptr;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3 (INVALID POINTER)" << std::endl;
		Data		*ptr = NULL;
		std::cout << "Create a Data object NULL" << std::endl;
		uintptr_t	uintPtr;
		Data		*deserializePtr;

		uintPtr = Serializer::serializer(ptr);
		deserializePtr = Serializer::deserialize(uintPtr);

		if (deserializePtr == NULL)
			std::cout << "deserialize pointer is NULL" << std::endl;
		else
			std::cout << "deserialize pointer is not NULL" << std::endl;
	}
	return (0);
}
