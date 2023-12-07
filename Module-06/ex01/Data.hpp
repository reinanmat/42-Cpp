/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:54:01 by revieira          #+#    #+#             */
/*   Updated: 2023/12/07 14:58:47 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Data
{
	public:
		Data();
		Data(int value);
		Data(const Data &obj);
		~Data();
		Data	&operator=(const Data &other);
		int		getValue();
		void	setValue(int value);
	
	private:
		int	_value;
};
