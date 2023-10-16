/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:31:39 by revieira          #+#    #+#             */
/*   Updated: 2023/10/16 17:43:06 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string	type;
		Animal();
		Animal(const Animal &obj);

	public:
		virtual ~Animal();
		Animal		  &operator=(Animal const &other);
		std::string	  getType(void) const;
		void		  setType(std::string type);
		virtual void  makeSound(void) const;
};
