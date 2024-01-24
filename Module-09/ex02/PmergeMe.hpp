/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:45:05 by revieira          #+#    #+#             */
/*   Updated: 2024/01/24 16:09:19 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>

#define VECTOR 0
#define DEQUE 1

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(std::vector<int> vector, std::deque<int> deque);
		PmergeMe(const PmergeMe &obj);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &other);
		void				sort(int containertype);
		std::vector<int>	getSortedVector() const;
		std::deque<int>		getSortedDeque() const;


		int jacobshal(int n);

		// template<typename T>
		// T buildJacobnsertionSequence(size_t size)
		// {
		// 	return ;
		// }
	
	private:
		int					_straggler;

		std::vector<int>	_unsortedVector;
		std::vector<int>	_sortedVector;
		std::vector<int>	_mainChain;
		std::vector<int>	_pendChain;

		void	_sortVector();


		std::deque<int>		_unsortedDeque;
		std::deque<int>		_sortedDeque;

		void	_sortDeque();
};

template <typename T>
T createContainer(size_t size, char **numbers)
{
	T	container;

	for (size_t	i = 0; i < size; i++)
		container.push_back(std::atoi(numbers[i]));
	return (container);
}

template<typename T>
static void	printContainer(T container)
{
	typename T::iterator	it;

	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << (it + 1 != container.end() ? ", " : "");
	std::cout << std::endl;
}
