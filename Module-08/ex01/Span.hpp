/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:45:47 by revieira          #+#    #+#             */
/*   Updated: 2024/01/17 16:03:05 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>
#include <vector>
#include <iostream>
#include <iterator>
#include <exception>
#include <algorithm>

class Span
{
	protected:
		Span();

	public:
		Span(size_t size);
		Span(const Span &obj);
		~Span();
		Span	&operator=(const Span &other);
		size_t	getSize(void) const;
		std::vector<int>	getNumbers(void) const;
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
		void	addNumber(int number);
		template <typename Iterator>
		void	addRange(Iterator itBegin, Iterator itEnd)
		{
			while (itBegin != itEnd)
			{
				this->addNumber(*itBegin);
				itBegin++;
			}
		}

	private:
		size_t				_size;
		std::vector<int>	_numbers;
};

std::ostream &operator<<(std::ostream &out, const Span &obj);
