/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:28:05 by revieira          #+#    #+#             */
/*   Updated: 2024/01/17 17:23:15 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
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
				std::stack<T>::operator=(other);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(void)
		{
			return (this->c.begin());
		}
		iterator	end(void)
		{
			return (this->c.end());
		}

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator	rbegin(void)
		{
			return (this->c.rbegin());
		}
		reverse_iterator	rend(void)
		{
			return (this->c.rend());
		}
};
