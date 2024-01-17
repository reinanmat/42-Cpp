/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:45:05 by revieira          #+#    #+#             */
/*   Updated: 2024/01/16 17:14:36 by revieira         ###   ########.fr       */
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
	
	private:
		std::vector<int>	_unsortedVector;
		std::vector<int>	_sortedVector;

		void	_sortVector();


		std::list<int>		_unsortedList;
		std::list<int>		_sortedList;

		void	_sortList();
};
