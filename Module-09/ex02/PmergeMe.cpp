/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:57:58 by revieira          #+#    #+#             */
/*   Updated: 2024/01/21 10:57:51 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* CONSTRUCTORS AND DESTRUTORS */
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> vector, std::list<int> list)
{
	this->_unsortedVector = vector;
	this->_unsortedList = list;
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
		return (*this);
	return (*this);
}

/* GETTERS */
std::vector<int>	PmergeMe::getSortedVector(void) const
{
	return (this->_sortedVector);
}

std::list<int>	PmergeMe::getSortedList(void) const
{
	return (this->_sortedList);
}

/* MEMBERS FUNCTIONS */
void	PmergeMe::sort(int cointainerType)
{
	if (cointainerType ==  VECTOR)
		this->_sortVector();
	else if (cointainerType == LIST)
		this->_sortList();
}

/* VECTOR */
static std::vector< std::pair<int, int> >	groupElementsIntoPairs(const std::vector<int> &vector)
{
	std::vector< std::pair<int, int> >	pairs;

	for (size_t i = 0; i < vector.size(); i+=2)
		pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
	return (pairs);
}

static void	printPairs(std::vector< std::pair<int, int> > &pairs)
{
	std::vector< std::pair<int, int> >::iterator it;

	for (it = pairs.begin(); it != pairs.end(); it++)
		std::cout << it->first << ", " << it->second << std::endl;
}

static void	merge(std::vector<std::pair<int, int> >	&pairs, int left, int mid, int right)
{
	std::vector<std::pair<int, int> >	leftPairs(pairs.begin() + left, pairs.begin() + mid + 1);
	std::vector<std::pair<int, int> >	rightPairs(pairs.begin() + mid + 1, pairs.begin() + right + 1);

	std::vector<std::pair<int, int> >::iterator	itLeft = leftPairs.begin();
	std::vector<std::pair<int, int> >::iterator	itRight = rightPairs.begin();
	std::vector<std::pair<int, int> >::iterator	itMerged = pairs.begin() + left;

	while (itLeft != leftPairs.end() && itRight != rightPairs.end())
	{
		if (itLeft->first <= itRight->first)
		{
			*itMerged = *itLeft;
			itLeft++;
		}
		else
		{
			*itMerged = *itRight;
			itRight++;
		}
		itMerged++;
	}
	while (itLeft != leftPairs.end())
	{
		*itMerged = *itLeft;
		itLeft++;
		itMerged++;
	}
	while (itRight != rightPairs.end())
	{
		*itMerged = *itRight;
		itRight++;
		itMerged++;
	}
}

static void	mergeSort(std::vector<std::pair<int, int> > &pairs, int begin, int end)
{
	if (begin >= end)
		return ;
	int mid = begin + (end - begin) / 2;
	mergeSort(pairs, begin, mid);
	mergeSort(pairs, mid + 1, end);
	merge(pairs, begin, mid, end);
}

static void	sortPairs(std::vector<std::pair<int, int> > &pairs)
{
	mergeSort(pairs, 0, pairs.size() - 1);
}

// static std::vector<int>	createMainChain(std::vector<std::pair<int, int> > &pairs)
// {
// 	std::vector<int> mainChain;
// 	std::vector<std::pair<int, int> >::iterator	it;
//
// 	for (it = pairs.begin(); it != pairs.end(); it++)
// 		mainChain.push_back(it->first);
// 	return (mainChain);
// }

// static void	insertRemainingElements(std::vector<int> &mainChain, std::vector<std::pair<int, int> > &pairs)
// {
// 	
// 	
// }

void	PmergeMe::_sortVector(void)
{
	std::vector< std::pair<int, int> > pairs;
	std::vector<int> mainChain;

	pairs = groupElementsIntoPairs(this->_unsortedVector);
	printPairs(pairs);
	std::cout << std::endl;
	sortPairs(pairs);
	printPairs(pairs);
	// mainChain = createMainChain(pairs);
}

/* LIST */
void	PmergeMe::_sortList(void)
{
	return ;
}
