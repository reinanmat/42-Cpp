/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:26:06 by revieira          #+#    #+#             */
/*   Updated: 2023/12/01 15:33:14 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp" 

AMateria::AMateria(std::string const &type) : _type(type)
{
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}
