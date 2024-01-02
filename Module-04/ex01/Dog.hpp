/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:13:03 by revieira          #+#    #+#             */
/*   Updated: 2023/12/19 16:23:44 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &obj);
		~Dog();
		Dog			&operator=(Dog const &other);
		std::string	getIdeaOfBrain(size_t index) const;
		void		setIdeaOfBrain(size_t index, std::string idea);
		void		makeSound(void) const;

	private:
		Brain	*_brain;
};
