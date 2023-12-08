/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:12:55 by revieira          #+#    #+#             */
/*   Updated: 2023/12/08 18:16:57 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	int	values[5] = {1, 5, 6, 7, 9};
	Array<int> array(5);

	for (int i = 0; i < 5; i++)
		array[i] = values[i];

	for (int i = 0; i < 5; i++)
		std::cout << array[i] << std::endl;
	return (0);
}
