/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:31:39 by revieira          #+#    #+#             */
/*   Updated: 2023/11/29 18:50:55 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#include <string>
#include <iostream>

class AAnimal
{
	protected:
		std::string	type;

	public:
		AAnimal(const AAnimal &obj);
		virtual	~AAnimal();
		AAnimal	&operator=(AAnimal const &other);
		std::string		getType(void) const;
		void			setType(std::string type);
		virtual void	makeSound(void) const;
	
	private:
		AAnimal();
};

void	prevTests(void);
