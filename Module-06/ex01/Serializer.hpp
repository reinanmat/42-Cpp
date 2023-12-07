/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:06:22 by revieira          #+#    #+#             */
/*   Updated: 2023/12/07 15:06:01 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer &obj);
		~Serializer();
		Serializer	&operator=(const Serializer &other);
		static Data			*deserialize(uintptr_t raw);
		static uintptr_t	serializer(Data *ptr);
};
