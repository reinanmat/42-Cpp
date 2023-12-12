/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:28:05 by revieira          #+#    #+#             */
/*   Updated: 2023/12/12 18:31:14 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>
#include <iterator>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack() {}
		~MutantStack() {}
		MutantStack(const MutantStack &obj)
		{
			if (this != &obj)
				*this = obj;
		}
		MutantStack	&operator=(const MutantStack &other)
		{
			if (this != &other)
				std::stack<T, Container>::operator=(other);
			return (*this);
		}
		typedef typename Container::iterator iterator;
		typename Container::iterator	begin(void)
		{
			return (this->c.begin());
		}
		typename Container::iterator	end(void)
		{
			return (this->c.end());
		}
};
