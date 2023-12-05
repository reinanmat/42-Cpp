/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:37:31 by revieira          #+#    #+#             */
/*   Updated: 2023/12/05 16:45:14 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137), _target("default")
{
	#ifdef DEBUG
		std::cout << BLU "ShrubberyCreationForm: Default Constructor Called" RESET << std::endl;
	#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137), _target(target)
{
	#ifdef DEBUG
		std::cout << BLU "ShrubberyCreationForm " << target << ": Constructor Called" RESET << std::endl;
	#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm("Shrubbery Creation", 145, 137)
{
	#ifdef DEBUG
		std::cout << BLU "ShrubberyCreationForm: Copy Constructor Called" RESET << std::endl;
	#endif
	if (this != &obj)
		*this = obj;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	#ifdef DEBUG
		std::cout << RED "ShrubberyCreationForm: Destructor Called" RESET << std::endl;
	#endif
}

/* OPERATORS OVERLOADING */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

/* MEMBERS FUNCTIONS */
const char *ShrubberyCreationForm::FailedToOpenFile::what() const throw()
{
	return ("AForm::exception : Failed to open a file");
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::checkExecute(executor);
	std::string filename;
	filename = this->_target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		throw (ShrubberyCreationForm::FailedToOpenFile());
	file << "          .     .  .      +     .      .          ." << std::endl;
	file << "     .       .      .     #       .           ."<< std::endl;
	file << "        .      .         ###            .      .      ."<< std::endl;
	file << "      .      .   \"#:. .:##\"##:. .:#\"  .      ."<< std::endl;
	file << "          .      . \"####\"###\"####\"  .\"" << std::endl;
	file << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       ." << std::endl;
	file << "  .             \"#########\"#########\"        .        ." << std::endl;
	file << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       ."<< std::endl;
	file << "     .     .  \"#######\"\"##\"##\"\"#######\"                  ."<< std::endl;
	file << "                .\"##\"#####\"#####\"##\"           .      ."<< std::endl;
	file << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     ."<< std::endl;
	file << "      .     \"#######\"##\"#####\"##\"#######\"      .     ."<< std::endl;
	file << "    .    .     \"#####\"\"#######\"\"#####\"    .      ."<< std::endl;
	file << "            .     \"      000      \"    .     ."<< std::endl;
	file << "       .         .   .   000     .        .       ." << std::endl;
	file << ".. .. ..................O000O........................ .. .." << std::endl;
	file.close();
}
