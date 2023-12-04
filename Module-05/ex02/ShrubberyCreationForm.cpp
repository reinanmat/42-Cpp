/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:37:31 by revieira          #+#    #+#             */
/*   Updated: 2023/12/04 17:21:23 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Robotomy Request Form", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Robotomy Request Form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm("Robotomy Request Form", 145, 137)
{
	if (this != &obj)
		*this = obj;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
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
	file << ".. .. ..................O000O........................ ...... ..." << std::endl;
	file.close();
}
