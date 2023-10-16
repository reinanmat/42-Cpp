/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:33:57 by revieira          #+#    #+#             */
/*   Updated: 2023/10/16 17:22:47 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &obj);
		~Brain();
		Brain	&operator=(const Brain &cpy);
		std::string	getIdea(size_t index) const;
		void		setIdea(size_t index, std::string idea);

	private:
		std::string	_ideas[100];
};
