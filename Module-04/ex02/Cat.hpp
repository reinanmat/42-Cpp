/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:17 by revieira          #+#    #+#             */
/*   Updated: 2023/12/19 16:25:44 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(const Cat &obj);
		~Cat();
		Cat			&operator=(Cat const &other);
		std::string	getIdeaOfBrain(size_t index) const;
		void		setIdeaOfBrain(size_t index, std::string idea);
		void		makeSound(void) const;

	private:
		Brain	*_brain;
};
