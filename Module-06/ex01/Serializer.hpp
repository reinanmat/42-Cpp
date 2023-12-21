/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:06:22 by revieira          #+#    #+#             */
/*   Updated: 2023/12/21 15:26:00 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	public:
		static Data			*deserialize(uintptr_t raw);
		static uintptr_t	serializer(Data *ptr);

	private:
		Serializer();
		Serializer(const Serializer &obj);
		~Serializer();
		Serializer	&operator=(const Serializer &other);
};
