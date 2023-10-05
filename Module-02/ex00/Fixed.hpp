/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:51:24 by revieira          #+#    #+#             */
/*   Updated: 2023/10/05 15:19:48 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &obj);
		~Fixed();
		Fixed	&operator= (const Fixed &cpy);
		int		getRawBits(void);
		void	setRawBits(int const raw);

	private:
		int					_rawBits;
		static const int 	_fractionalBits = 8;
};
