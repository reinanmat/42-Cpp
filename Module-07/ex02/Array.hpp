/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:51:32 by revieira          #+#    #+#             */
/*   Updated: 2023/12/08 18:20:09 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

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
				delete this->_array;
				this->_size = other._size;
				this->_array = new T[other._size];
				for (size_t i = 0; i < other._size; i++)
					this->_array[i] = other._array[i];
			}
		}
		T		&operator[](int index)
		{
			if (index >= (int)this->_size)
				throw ("index out of range");
			return (this->_array[index]);

		}
		int		size(void)
		{
			return (this->_size);	
		}
	
	private:
		T		*_array;
		size_t	_size;
};
