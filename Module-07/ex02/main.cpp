/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:12:55 by revieira          #+#    #+#             */
/*   Updated: 2024/01/11 15:58:05 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

static void	tryingAcessIndexInArray(Array<int> &array, int index)
{
	try {
		std::cout << "Trying to acess the index: " << index << "\t->\t";
		int value = array[index];
		std::cout << "value: " << value << std::endl;;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

int	main(void)
{
	{
		std::cout << "TEST 1" << std::endl;
		int	values[3] = {1, 2, 3};

		Array<int> a(3);
		for (int i = 0; i < 3; i++)
			a[i] = values[i];
		Array<int> b(a);
		Array<int> c;
		c = a;
		std::cout << "Array A:" << std::endl;
		std::cout << "[";
		for (int i = 0; i < 2; i++)
			std::cout << a[i] << ", ";
		std::cout << a[2] << "]" << std::endl ;

		std::cout << "Array B (COPY CONSTRUCTOR):" << std::endl;
		std::cout << "[";
		for (int i = 0; i < 2; i++)
			std::cout << b[i] << ", ";
		std::cout << b[2] << "]" << std::endl ;

		std::cout << "Array C (OVERLOADING OPERATOR =):" << std::endl;
		std::cout << "[";
		for (int i = 0; i < 2; i++)
			std::cout << c[i] << ", ";
		std::cout << c[2] << "]" << std::endl ;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2" << std::endl;

		Array<std::string>	array(5);

		for (int i = 0; i < 5; i++)
			array[i] = "a";
		std::cout << "(before) Array: [";
		for (int i = 0; i < 4; i++)
			std::cout << array[i] << ", ";
		std::cout << array[4] << "]" << std::endl ;
		array[0] = "a";
		array[1] = "ab";
		array[2] = "abc";
		array[3] = "abcd";
		array[4] = "abcde";
		std::cout << "(after)  Array: [";
		for (int i = 0; i < 4; i++)
			std::cout << array[i] << ", ";
		std::cout << array[4] << "]" << std::endl ;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3 (ACESSING INDEXS)" << std::endl;

		Array<int>	array(5);
		for (int i = 0; i < 5; i++)
			array[i] = i + 1;
		std::cout << "Array: [";
		for (int i = 0; i < 4; i++)
			std::cout << array[i] << ", ";
		std::cout << array[4] << "]" << std::endl ;
		tryingAcessIndexInArray(array, 0);
		tryingAcessIndexInArray(array, 1);
		tryingAcessIndexInArray(array, 2);
		tryingAcessIndexInArray(array, -1);
		tryingAcessIndexInArray(array, 5);
		tryingAcessIndexInArray(array, -42);
	}
	return (0);
}
