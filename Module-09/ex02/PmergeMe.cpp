/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:57:58 by revieira          #+#    #+#             */
/*   Updated: 2024/01/30 16:20:29 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* CONSTRUCTORS AND DESTRUTORS */
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> vector, std::deque<int> deque)
{
	this->_unsortedVector = vector;
	this->_unsortedDeque = deque;
	if (vector.size() % 2 == 0)
		this->_straggler = -1;
	else
	{
		this->_straggler = vector.back();
		this->_unsortedVector.pop_back();
		this->_unsortedDeque.pop_back();
	}
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	if (this != &obj)
		*this = obj;
}

PmergeMe::~PmergeMe() {}

/* OPERATORS OVERLOADING */
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_straggler = other._straggler;
		this->_unsortedDeque = other._unsortedDeque;
		this->_unsortedVector = other._unsortedVector;
	}
	return (*this);
}

/* GETTERS */
std::vector<int>	PmergeMe::getSortedVector(void) const
{
	return (this->_sortedVector);
}

std::deque<int>	PmergeMe::getSortedDeque(void) const
{
	return (this->_sortedDeque);
}

/* MEMBERS FUNCTIONS */
void	PmergeMe::sort(int cointainerType)
{
	if (cointainerType ==  VECTOR)
		this->_sortVector();
	else if (cointainerType == DEQUE)
		this->_sortDeque();
}

int	jacobshal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobshal(n - 1) + 2 * jacobshal(n - 2));
}

/* VECTOR */
static std::vector<t_pairsInts>	groupElementsIntoPairs(const std::vector<int> &vector)
{
	std::vector<t_pairsInts>	pairs;

	for (size_t i = 0; i < vector.size(); i+=2)
	{
		if (vector[i] > vector[i + 1])
			pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
		else
			pairs.push_back(std::make_pair(vector[i + 1], vector[i]));
	}
	return (pairs);
}

void	PmergeMe::_sortVector(void)
{
	std::vector<t_pairsInts>	pairs;
	std::vector<int>	mainChain;
	std::vector<int>	pendChain;
	std::vector<int>	insertionSequence;

	if (this->_unsortedVector.size() < 1)
		return ;
	pairs = groupElementsIntoPairs(this->_unsortedVector);
	mergeSort(pairs, pairs.begin(), pairs.end() - 1);
	for (std::vector<t_pairsInts>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		mainChain.push_back(it->first);
		pendChain.push_back(it->second);
	}
	if (this->_straggler != -1)
		pendChain.push_back(this->_straggler);
	mainChain.insert(mainChain.begin(), pendChain[0]);
	insertionSequence = buildJacobInsertionSequence<std::vector<int> >(pendChain.size() - 1);
	if (!insertionSequence.empty())
	{
		for (size_t i = 0; i < pendChain.size() - 1; i++)
		{
			int item = pendChain[insertionSequence[i]];
			if (item < mainChain[0])
			{
				mainChain.insert(mainChain.begin(), item);
				continue ;
			}
			for (std::vector<int>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
			{
				if (item > *it && (it + 1 == mainChain.end() || item < *(it + 1)))
				{
					mainChain.insert(it + 1, item);
					break ;
				}
			}
		}
	}
	this->_sortedVector = mainChain;
}

/* DEQUE */
static std::deque<t_pairsInts>	groupElementsIntoPairs(std::deque<int> &deque)
{
	std::deque<t_pairsInts>	pairs;

	for (size_t i = 0; i < deque.size(); i+=2)
	{
		if (deque[i] > deque[i + 1])
			pairs.push_back(std::make_pair(deque[i], deque[i + 1]));
		else
			pairs.push_back(std::make_pair(deque[i + 1], deque[i]));
	}
	return (pairs);
}

void	PmergeMe::_sortDeque(void)
{
	std::deque<t_pairsInts>	pairs;
	std::deque<int>	mainChain;
	std::deque<int>	pendChain;
	std::deque<int>	insertionSequence;

	if (this->_unsortedDeque.size() < 1)
		return ;
	pairs = groupElementsIntoPairs(this->_unsortedDeque);
	mergeSort(pairs, pairs.begin(), pairs.end() - 1);
	for (std::deque<t_pairsInts>::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		mainChain.push_back(it->first);
		pendChain.push_back(it->second);
	}
	if (this->_straggler != -1)
		pendChain.push_back(this->_straggler);
	mainChain.insert(mainChain.begin(), pendChain[0]);
	insertionSequence = buildJacobInsertionSequence<std::deque<int> >(pendChain.size() - 1);
	if (!insertionSequence.empty())
	{
		for (size_t i = 0; i < pendChain.size() - 1; i++)
		{
			int item = pendChain[insertionSequence[i]];
			if (item < mainChain[0])
			{
				mainChain.insert(mainChain.begin(), item);
				continue ;
			}
			for (std::deque<int>::iterator it = mainChain.begin(); it != mainChain.end(); it++)
			{
				if (item > *it && (it + 1 == mainChain.end() || item < *(it + 1)))
				{
					mainChain.insert(it + 1, item);
					break ;
				}
			}
		}
	}
	this->_sortedDeque = mainChain;
}
