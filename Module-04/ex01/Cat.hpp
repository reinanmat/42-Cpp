/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:17 by revieira          #+#    #+#             */
/*   Updated: 2023/11/29 17:39:01 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Brain &brain);
		Cat(const Cat &obj);
		~Cat();
		Cat	&operator=(Cat const &other);
		void  makeSound(void) const;

	private:
		Brain	*_brain;
};
