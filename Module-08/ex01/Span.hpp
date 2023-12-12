/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:45:47 by revieira          #+#    #+#             */
/*   Updated: 2023/12/12 15:50:45 by revieira         ###   ########.fr       */
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
		void	addNumber(int number);
		void	addNumber(std::vector<int>::const_iterator itBegin, std::vector<int>::const_iterator itEnd);
		size_t				getSize(void) const;
		std::vector<int>	getVector(void) const;
		size_t				shortestSpan(void) const;
		size_t				longestSpan(void) const;

	private:
		size_t				_size;
		std::vector<int>	_vec;
};

std::ostream &operator<<(std::ostream &out, const Span &obj);
