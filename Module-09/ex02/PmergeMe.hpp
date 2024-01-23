/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:45:05 by revieira          #+#    #+#             */
/*   Updated: 2024/01/22 23:05:21 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

#define VECTOR 0
#define LIST 1

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(std::vector<int> vector, std::list<int> list);
		PmergeMe(const PmergeMe &obj);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &other);
		void				sort(int containertype);
		std::vector<int>	getSortedVector() const;
		std::list<int>		getSortedList() const;

		template<typename T>
		static void	printContainer(T container)
		{
			typename T::iterator	it;

			for (it = container.begin(); it != container.end(); it++)
				std::cout << *it;
			std::cout << std::endl;
		}

		// int jacobshal(int num);
		//
		// template<typename T>
		// T createJacobsthalSequence(size_t size)
		// {
		// 	return ;
		// }
	
	private:
		bool				_hasStraggler;
		int					_straggler;

		std::vector<int>	_unsortedVector;
		std::vector<int>	_sortedVector;
		std::vector<int>	_mainChain;
		std::vector<int>	_pendChain;

		void	_sortVector();
		void	_initMainAndPendChains(std::vector<std::pair<int, int> > &pairs);


		std::list<int>		_unsortedList;
		std::list<int>		_sortedList;

		void	_sortList();
};
