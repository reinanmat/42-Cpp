/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:04:41 by revieira          #+#    #+#             */
/*   Updated: 2023/12/07 15:15:01 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data		*dataPtr = new Data(42);
	uintptr_t	uintPtr;
	Data		*otherDataPtr;

	uintPtr = Serializer::serializer(dataPtr);
	otherDataPtr = Serializer::deserialize(uintPtr); 

	std::cout << "data ptr: " << dataPtr->getValue() << std::endl;
	std::cout << "other data ptr: " << otherDataPtr->getValue() << std::endl;

	delete	dataPtr;
}
