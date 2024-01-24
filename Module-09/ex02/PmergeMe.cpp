/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:57:58 by revieira          #+#    #+#             */
/*   Updated: 2024/01/24 10:52:33 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* CONSTRUCTORS AND DESTRUTORS */
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> vector, std::deque<int> deque)
{
	this->_unsortedVector = vector;
	this->_unsortedDeque = deque;
	if (vector.size() % 2 == 1)
	{
		this->_hasStraggler = true;
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
		this->_hasStraggler = other._hasStraggler;
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

int	PmergeMe::jacobshal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobshal(n - 1) + 2 * jacobshal(n - 2));
}

/* VECTOR */
static std::vector< std::pair<int, int> >	groupElementsIntoPairs(const std::vector<int> &vector)
{
	std::vector< std::pair<int, int> >	pairs;

	for (size_t i = 0; i < vector.size(); i+=2)
	{
		if (vector[i] > vector[i + 1])
			pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
		else
			pairs.push_back(std::make_pair(vector[i + 1], vector[i]));
	}
	return (pairs);
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
			*itMerged++ = *itLeft++;
		else
			*itMerged++ = *itRight++;
	}
	while (itLeft != leftPairs.end())
		*itMerged++ = *itLeft++;
	while (itRight != rightPairs.end())
		*itMerged++ = *itRight++;
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

void	PmergeMe::_sortVector(void)
{
	if (this->_unsortedVector.size() < 1)
		return ;

	std::vector< std::pair<int, int> > pairs;
	pairs = groupElementsIntoPairs(this->_unsortedVector);
	sortPairs(pairs);

	std::vector<std::pair<int, int> >::iterator	it;
	std::vector<int>	mainChain;
	std::vector<int>	pendChain;
	for (it = pairs.begin(); it != pairs.end(); it++)
	{
		mainChain.push_back(it->first);
		pendChain.push_back(it->second);
	}

	if (this->_hasStraggler)
		pendChain.push_back(this->_straggler);

	std::cout << "Main Chain: ";
	printContainer(mainChain);
	std::cout << "Pend Chain: ";
	printContainer(pendChain);
}

/* LIST */
static std::deque< std::pair<int, int> >	groupElementsIntoPairs(std::deque<int> &deque)
{
	std::deque< std::pair<int, int> >	pairs;

	for (size_t i = 0; i < deque.size(); i+=2)
	{
		if (deque[i] > deque[i + 1])
			pairs.push_back(std::make_pair(deque[i], deque[i + 1]));
		else
			pairs.push_back(std::make_pair(deque[i + 1], deque[i]));
	}
	return (pairs);
}

static void	merge(std::deque<std::pair<int, int> >	&pairs, int left, int mid, int right)
{
	std::deque<std::pair<int, int> >	leftPairs(pairs.begin() + left, pairs.begin() + mid + 1);
	std::deque<std::pair<int, int> >	rightPairs(pairs.begin() + mid + 1, pairs.begin() + right + 1);

	std::deque<std::pair<int, int> >::iterator	itLeft = leftPairs.begin();
	std::deque<std::pair<int, int> >::iterator	itRight = rightPairs.begin();
	std::deque<std::pair<int, int> >::iterator	itMerged = pairs.begin() + left;

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

static void	mergeSort(std::deque<std::pair<int, int> > &pairs, int begin, int end)
{
	if (begin >= end)
		return ;
	int mid = begin + (end - begin) / 2;
	mergeSort(pairs, begin, mid);
	mergeSort(pairs, mid + 1, end);
	merge(pairs, begin, mid, end);
}

static void	sortPairs(std::deque<std::pair<int, int> > &pairs)
{
	mergeSort(pairs, 0, pairs.size() - 1);
}

void	PmergeMe::_sortDeque(void)
{
	if (this->_unsortedDeque.size() < 1)
		return ;

	std::deque<std::pair<int, int> >	pairs = groupElementsIntoPairs(this->_unsortedDeque);

	sortPairs(pairs);

	std::deque<std::pair<int, int> >::iterator	it;
	std::deque<int>	mainChain;
	std::deque<int>	pendChain;
	for (it = pairs.begin(); it != pairs.end(); it++)
	{
		mainChain.push_back(it->first);
		pendChain.push_back(it->second);
	}

	if (this->_hasStraggler)
		pendChain.push_back(this->_straggler);

	mainChain.insert(mainChain.begin(), pendChain[0]);
	// pendChain.erase(mainChain.begin());

	std::cout << "Main Chain: ";
	printContainer(mainChain);

	std::cout << "Pend Chain: ";
	printContainer(pendChain);

}
