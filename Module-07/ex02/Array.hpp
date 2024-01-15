/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:51:32 by revieira          #+#    #+#             */
/*   Updated: 2024/01/15 16:47:38 by revieira         ###   ########.fr       */
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
			this->_array = NULL;
		};

		Array(unsigned int size)
		{
			this->_size = size;
			this->_array = new T[size];
		};

		Array(const Array &obj)
		{
			this->_size = 0;
			this->_array = NULL;
			if (this != &obj)
				*this = obj;
		}

		~Array()
		{
			if (this->_array)
			{
				delete[] this->_array;
				this->_size = 0;
				this->_array = NULL;
			}
		};

		Array	&operator=(const Array &other)
		{
			if (this != &other)
			{
				this->~Array();
				if (other._size == 0)
					return (*this);
				new(this) Array(other._size);
				for (unsigned int i = 0; i < other._size; i++)
					this->_array[i] = other._array[i];
			}
			return (*this);
		}

		T	&operator[](int index)
		{
			if (index < 0 || index >= (int)this->_size)
				throw (std::out_of_range("Error: Index out of range"));
			return (this->_array[index]);

		}

		int	size(void)
		{
			return (this->_size);	
		}
	
	private:
		T				*_array;
		unsigned int	_size;
};
