/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:45:47 by revieira          #+#    #+#             */
/*   Updated: 2023/12/11 18:52:43 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Span
{
	protected:
		Span();

	public:
		Span(unsigned int size);
		Span(const Span &obj);
		~Span();
		Span	&operator=(const Span &other);

		void	addNumber(int number);
		int		shortestSpan(void);
		int		longestSpan(void);

	private:
		unsigned int	_size;
};
