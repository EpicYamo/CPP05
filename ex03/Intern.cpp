/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 20:59:44 by aaycan            #+#    #+#             */
/*   Updated: 2026/09/24 22:16:58 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() {}

static AForm *createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *createPardon(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string name, const std::string target)
{
	std::string	formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm		*(*formCreators[3])(const std::string &) = {createShrubbery, createRobotomy, createPardon};
	int			i;

	i = 0;
	while ((i < 3) && (name != formNames[i]))
		i++;
	if (i == 3)
	{
		std::cout << "Intern: unknown form \"" << name << "\"" << std::endl;
		return (NULL);
	}
	std::cout << "Intern creates " << name << std::endl;
	return (formCreators[i](target));
}
