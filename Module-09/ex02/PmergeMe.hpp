/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:45:05 by revieira          #+#    #+#             */
/*   Updated: 2024/01/29 17:15:06 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <limits>
#include <iomanip>

#define VECTOR 0
#define DEQUE 1

typedef std::pair<int, int> t_pairsInts;

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
	
	private:
		int					_straggler;

		std::vector<int>	_unsortedVector;
		std::vector<int>	_sortedVector;
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
void	printContainer(T container)
{
	typename T::iterator	it;

	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << (it + 1 != container.end() ? ", " : "");
	std::cout << std::endl;
}

template <typename T>
void	merge(typename T::iterator begin, typename T::iterator mid, typename T::iterator end)
{
	T	leftPairs(begin, mid + 1);
	T	rightPairs(mid + 1, end + 1);

	typename T::iterator	itLeft = leftPairs.begin();
	typename T::iterator	itRight = rightPairs.begin();
	typename T::iterator	itMerged = begin;

	while (itLeft != leftPairs.end() && itRight != rightPairs.end())
	{
		if (itLeft->first <= itRight->first)
			*itMerged++ = *itLeft++;
		else
			*itMerged++ = *itRight++;
	}
	while (itLeft != leftPairs.end())
		*itMerged++ = *itLeft++;
	while (itRight != rightPairs.end())
		*itMerged++ = *itRight++;
}

template <typename T>
void	mergeSort(T &pairs, typename T::iterator begin, typename T::iterator end)
{
	if (begin >= end)
		return  ;
	typename T::iterator mid = begin + std::distance(begin, end) / 2;
	mergeSort<T>(pairs, begin, mid);
	mergeSort<T>(pairs, mid + 1, end);
	merge<T>(begin, mid, end);
}

int jacobshal(int n);

template<typename T>
T buildJacobInsertionSequence(size_t size)
{
	T	sequence;
	int	indexJacob = 2;
	int curr;

	if (size < 1)
		return (sequence);
	curr = jacobshal(indexJacob);
	sequence.push_back(curr);
	indexJacob++;
	while (sequence.size() < size)
	{
		curr = jacobshal(indexJacob++);
		if (curr > (int)size)
			curr = size;
		while (sequence.size() < size && curr > 0)
		{
			sequence.push_back(curr);
			if (std::find(sequence.begin(), sequence.end(), curr - 1) != sequence.end())
				break ;
			curr--;
		}
	}
	return (sequence);
}
