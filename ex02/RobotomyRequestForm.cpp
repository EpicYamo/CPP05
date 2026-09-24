/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 03:02:16 by aaycan            #+#    #+#             */
/*   Updated: 2026/09/24 19:53:41 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	AForm::operator=(other);
	_target = other._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target) {}

void RobotomyRequestForm::executeAction() const
{
	int	n;

	n = rand() % 2;
	std::cout << "Bzzzzzt Bzzzz Bzzzt..." << std::endl;
	if (n == 1)
		std::cout << getName() << " has been robotomized successfully." << std::endl;		
	else
		std::cout << "Unfortunately, the robotomy of " << getName() << " failed due to drill getting stuck on the previous robot's head." << std::endl;
}
