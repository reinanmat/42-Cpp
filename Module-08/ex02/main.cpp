/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:54:27 by revieira          #+#    #+#             */
/*   Updated: 2024/01/17 17:25:48 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <iostream>
#include <cstdlib>

static int	*randomNumbers(size_t size)
{
	int *numbers = new int[size];
	for (size_t i = 0; i < size; i++)
		numbers[i] = rand() % 100;
	return (numbers);
}

int	main(void)
{
	{
		std::cout << "TEST 1 (SUBJECT TEST)" << std::endl;
		MutantStack<int> mstack;
		std::cout << "MutantStack created" << std::endl;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		std::cout << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "Print MutantStack, size: " << mstack.size() << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;
		std::stack<int> s(mstack);
		std::cout << "Stack created using MutantStack" << std::endl;
		std::cout << "Print Stack(inverse), size: " << s.size() << std::endl;
		while (s.size() != 0)
		{
			std::cout << s.top() << std::endl;
			s.pop();
		}
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2 (COPY CONSTRUCTOR AND OPERATOR=)" << std::endl;
		MutantStack<int>	a;
		a.push(21);
		a.push(24);
		a.push(-42);
		a.push(42);
		a.push(43);
		MutantStack<int>	b(a);
		MutantStack<int>	c = b;

		MutantStack<int>::iterator	itA = a.begin();
		MutantStack<int>::iterator	iteA = a.end();
		std::cout << "MutantStack A(ORIGINAL), size: " << a.size() <<	" -> [";
		while (itA != iteA)
		{
			std::cout << *itA << (itA + 1 != iteA ? ", " : "]");
			++itA;
		}
		std::cout << std::endl;
		std::cout << "top: " << a.top() << std::endl;
		MutantStack<int>::iterator	itB = a.begin();
		MutantStack<int>::iterator	iteB = a.end();

		std::cout << "MutantStack B(COPY CONSTRUCTOR), size: " << b.size() <<	" -> [";
		while (itB != iteB)
		{
			std::cout << *itB << (itB + 1 != iteB ? ", " : "]");
			++itB;
		}
		std::cout << std::endl;
		std::cout << "top: " << b.top() << std::endl;

		MutantStack<int>::iterator	itC = a.begin();
		MutantStack<int>::iterator	iteC = a.end();
		std::cout << "MutantStack C(ASSIGNMENT OPERATOR OVERLOADING), size: " << c.size() <<	" -> [";
		while (itC != iteC)
		{
			std::cout << *itC << (itC + 1 != iteC ? ", " : "]");
			++itC;
		}
		std::cout << std::endl;
		std::cout << "top: " << c.top() << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3 (ITERATORS)" << std::endl;
		MutantStack<int>	mstack;
		mstack.push(1);
		mstack.push(2);
		mstack.push(3);
		mstack.push(4);
		mstack.push(5);

		MutantStack<int>::iterator	it = mstack.begin();
		MutantStack<int>::iterator	ite = mstack.end();
		std::cout << "MutantStack (NORMAL ITERATOR),	size: " << mstack.size() <<	" -> [";
		while (it != ite)
		{
			std::cout << *it << (it + 1 != ite ? ", " : "]");
			++it;
		}
		std::cout << std::endl;

		MutantStack<int>::reverse_iterator	rIt = mstack.rbegin();
		MutantStack<int>::reverse_iterator	rIte = mstack.rend();
		std::cout << "MutantStack (REVERSE ITERATOR),	size: " << mstack.size() <<	" -> [";
		while (rIt != rIte)
		{
			std::cout << *rIt << (rIt + 1 != rIte ? ", " : "]");
			++rIt;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 4 (MUTANTSTACK VS LIST)" << std::endl;
		srand(time(NULL));
		size_t	size = 10;
		int *numbers = randomNumbers(size);

		MutantStack<int>	mstack;
		for (size_t i = 0; i < size; i++)
			mstack.push(numbers[i]);
		MutantStack<int>::iterator	itMStack = mstack.begin();
		MutantStack<int>::iterator	iteMStack = mstack.end();
		std::cout << "MutantStack,	size: " << mstack.size() <<	" -> [";
		while (itMStack != iteMStack)
		{
			std::cout << *itMStack << (itMStack + 1 != iteMStack ? ", " : "]");
			++itMStack;
		}
		std::cout << std::endl;

		std::list<int> list;
		for (size_t i = 0; i < size; i++)
			list.push_back(numbers[i]);
		std::list<int>::iterator	itList = list.begin();
		std::list<int>::iterator	iteList = list.end();
		std::cout << "Container List,	size: " << list.size() <<	" -> [";
		while (itList != iteList)
			std::cout << *itList << (++itList != iteList ? ", " : "]");
		std::cout << std::endl;
		delete[] numbers;
	}
}
