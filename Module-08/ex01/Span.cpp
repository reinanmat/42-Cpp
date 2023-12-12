/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:34:42 by revieira          #+#    #+#             */
/*   Updated: 2023/12/12 17:19:44 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* CONSTRUCTORS AND DESTRUCTORS */
Span::Span() : _size(0)
{
	
}

Span::Span(size_t size) : _size(size)
{
}

Span::Span(const Span &obj)
{
	if (this != &obj)
		*this = obj;
}

Span::~Span()
{
	
}

/* OPERATORS OVERLOADING */
Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_size = other._size;
		this->_vec = other._vec;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Span &obj)
{
	std::vector<int> tmp;

	tmp = obj.getVector();
	out << "size: " << obj.getSize() << std::endl;
	out << "[";
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
		out << *it << ((it + 1) != tmp.end() ? ", " : "]");
	return (out);
}

/* GETTERS */
std::vector<int>	Span::getVector(void) const
{
	return (this->_vec);
}

size_t	Span::getSize(void) const
{
	return (this->_size);
}

/* MEMBER FUNCTIONS */
void	Span::addNumber(int number)
{
	if (this->_vec.size() >= this->_size)
		throw std::out_of_range("Unable to add (int number) maximum capacity reached");
	else
		this->_vec.push_back(number);
}

void	Span::addNumber(std::vector<int>::const_iterator itBegin, std::vector<int>::const_iterator itEnd)
{
	while (itBegin != itEnd)
	{
		this->addNumber(*itBegin);
		itBegin++;
	}
}

size_t	Span::shortestSpan(void) const
{
	std::vector<int>			tmp;
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	itNext;
	size_t	smallest = -1;

	tmp = this->_vec;
	std::sort(tmp.begin(), tmp.end());
	it = tmp.begin();
	for (itNext = (tmp.begin() + 1); itNext != tmp.end(); itNext++)
	{
		if (smallest == 1)
			break ;
		if (*itNext != *it && size_t(*itNext - *it) < smallest)
			smallest = *itNext - *it;
		it++;
	}
	return (smallest);
}

size_t	Span::longestSpan(void) const
{
	std::vector<int> tmp = this->_vec;

	std::sort(tmp.begin(), tmp.end());
	return (*(tmp.end() - 1) - *tmp.begin());
}
