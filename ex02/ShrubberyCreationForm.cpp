/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 03:02:21 by aaycan            #+#    #+#             */
/*   Updated: 2026/09/24 19:10:37 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	_target = other._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream outFile((_target + "_shrubbery").c_str());
	if (outFile)
	{
		outFile << "        *\n";
		outFile << "       ***\n";
		outFile << "      *****\n";
		outFile << "     *******\n";
		outFile << "    *********\n";
		outFile << "   ***********\n";
		outFile << "  *************\n";
		outFile << " ***************\n";
		outFile << "*****************\n";
		outFile << "        |\n";
		outFile << "        |\n";
		outFile.close();
	}
	else
		throw ShrubberyCreationForm::FileCreationException();
}

const char *ShrubberyCreationForm::FileCreationException::what() const throw()
{
	return ("Could not open the file");
}
