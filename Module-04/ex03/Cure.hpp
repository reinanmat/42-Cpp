/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:37:29 by revieira          #+#    #+#             */
/*   Updated: 2023/12/01 14:42:40 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &obj);
		~Cure();
		Cure		&operator=(const Cure &obj);
		AMateria	*clone();
		void		use(ICharacter &target);
};
