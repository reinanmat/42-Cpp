/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:51:32 by revieira          #+#    #+#             */
/*   Updated: 2024/01/09 17:37:46 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array
{
	public:
		Array()
		{
			this->_size = 0;
			this->_array = new T[0];
		};

		Array(unsigned int size)
		{
			this->_size = size;
			this->_array = new T[size];
		};

		Array(const Array &obj)
		{
			this->_size = 0;
			this->_array = new T[0];
			if (this != &obj)
				*this = obj;
		}

		~Array()
		{
			delete[] this->_array;
		};

		Array	&operator=(const Array &other)
		{
			if (this != &other)
			{
				this->~Array();
				this->_size = other._size;
				this->_array = new T[other._size];
				for (size_t i = 0; i < other._size; i++)
					this->_array[i] = other._array[i];
			}
			return (*this);
		}

		T	&operator[](int index)
		{
			if (index < 0 || index >= (int)this->_size)
				throw (std::out_of_range("Index out of range"));
			return (this->_array[index]);

		}

		int	size(void)
		{
			return (this->_size);	
		}
	
	private:
		T		*_array;
		size_t	_size;
};
