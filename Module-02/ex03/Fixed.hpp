/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:51:24 by revieira          #+#    #+#             */
/*   Updated: 2023/11/20 16:19:06 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &obj);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		int				toInt(void) const;
		float			toFloat(void) const;
		Fixed			&operator=(const Fixed &other);
		Fixed			operator+(const Fixed &x) const;
		Fixed			operator-(const Fixed &x) const;
		Fixed			operator*(const Fixed &x) const;
		Fixed			operator/(const Fixed &x) const;
		bool			operator==(const Fixed &cmp) const;
		bool			operator!=(const Fixed &cmp) const;
		bool			operator<(const Fixed &cmp) const;
		bool			operator>(const Fixed &cmp) const;
		bool			operator>=(const Fixed &cmp) const;
		bool			operator<=(const Fixed &cmp) const;
		Fixed			operator++(int);
		Fixed			operator--(int);
		Fixed			&operator--();
		Fixed			&operator++();
		static Fixed	&min(Fixed &a, Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed	&max(const Fixed &a, const Fixed &b);

	private:
		int					_fixedPoint;
		static const int 	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &obj);
