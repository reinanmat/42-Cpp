/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:12:55 by revieira          #+#    #+#             */
/*   Updated: 2023/12/14 14:39:22 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <cstring>

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &obj);
		~MateriaSource();
		MateriaSource	&operator=(const MateriaSource &other);
		void learnMateria(AMateria* obj);
		AMateria* createMateria(std::string const & type);
	
	private:
		int			_size;
		AMateria	*_types[4];
};
