/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:51:24 by revieira          #+#    #+#             */
/*   Updated: 2023/10/05 20:19:07 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &obj);
		Fixed(const int &num);
		Fixed(const double &num);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void);
		float	toFloat(void);
		Fixed	&operator=(const Fixed &cpy);

	private:
		int					_fixedPoint;
		static const int 	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &obj);
