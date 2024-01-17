/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:34:42 by revieira          #+#    #+#             */
/*   Updated: 2024/01/17 16:33:22 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* CONSTRUCTORS AND DESTRUCTORS */
Span::Span() : _size(0) {}

Span::Span(size_t size) : _size(size) {}

Span::Span(const Span &obj)
{
	if (this != &obj)
		*this = obj;
}

Span::~Span() {}

/* OPERATORS OVERLOADING */
Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_size = other._size;
		this->_numbers = other._numbers;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Span &obj)
{
	std::vector<int> tmp;

	tmp = obj.getNumbers();
	out << "size: " << obj.getSize() << std::endl;
	if (tmp.size() < 1)
	{
		out << "[]";
		return (out);
	}
	out << "[";
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
		out << *it << ((it + 1) != tmp.end() ? ", " : "]");
	return (out);
}

/* GETTERS */
size_t	Span::getSize(void) const
{
	return (this->_size);
}

std::vector<int>	Span::getNumbers(void) const
{
	return (this->_numbers);
}

/* MEMBER FUNCTIONS */
void	Span::addNumber(int number)
{
	if (this->_numbers.size() >= this->_size)
		throw std::runtime_error("Error: Unable to add (int number) maximum capacity reached");
	else
		this->_numbers.push_back(number);
}

int	Span::shortestSpan(void) const
{
	if (this->_numbers.size() <= 1)
		throw std::runtime_error("Error: No span can be found");
	std::vector<int>	tmp;
	tmp = this->_numbers;
	std::sort(tmp.begin(), tmp.end());
	int	shortest = std::abs(tmp[0] - tmp[1]);
	for (size_t i = 1; i + 1 < tmp.size(); i++)
		shortest = std::min(shortest, std::abs(tmp[i] - tmp[i + 1]));
	return (shortest);
}

int	Span::longestSpan(void) const
{
	if (this->_numbers.size() <= 1)
		throw std::runtime_error("Error: No span can be found");
	std::vector<int> tmp = this->_numbers;
	std::sort(tmp.begin(), tmp.end());
	return (std::abs(*(tmp.end() - 1) - *tmp.begin()));
}
