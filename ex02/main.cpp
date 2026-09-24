/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 03:35:30 by aaycan            #+#    #+#             */
/*   Updated: 2026/09/24 20:53:27 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	std::cout << "Signing Tests" << std::endl;
	{
		Bureaucrat				highGrade("Alice", 1);
		Bureaucrat				lowGrade("Bob", 150);
		ShrubberyCreationForm	form("garden");
		highGrade.signForm(form);
		lowGrade.signForm(form);
	}
	std::cout << "\nSigning boundary tests (grade == gradeToSign)" << std::endl;
	{
		Bureaucrat				exact("Carl", 145);
		ShrubberyCreationForm	form("boundary");
		exact.signForm(form);
	}
	std::cout << "\nTry to execute without signing" << std::endl;
	{
		Bureaucrat				bureaucrat("Dave", 1);
		ShrubberyCreationForm	form("unsigned");
		bureaucrat.executeForm(form);
	}
	std::cout << "\nTry to execute with low grade" << std::endl;
	{
		Bureaucrat				signer("Erin", 1);
		Bureaucrat				lowGrade("Frank", 150);
		ShrubberyCreationForm	form("lowGrade");
		signer.signForm(form);
		lowGrade.executeForm(form);
	}
	std::cout << "\nExecute boundary tests (success test) (grade == gradeToExecute)" << std::endl;
	{
		Bureaucrat				boundary("Grace", 137);
		ShrubberyCreationForm	form("exactexec");
		boundary.signForm(form);
		boundary.executeForm(form);
	}
	std::cout << "\nRobotomy Request Form (multiple runs to see both outcomes)" << std::endl;
	{
		Bureaucrat			bureaucrat("Ivan", 1);
		RobotomyRequestForm	form("Bender");
		bureaucrat.signForm(form);
		for (int i = 0; i < 6; i++)
			bureaucrat.executeForm(form);
	}
	std::cout << "\nPresidential Pardon Form" << std::endl;
	{
		Bureaucrat				bureaucrat("Julia", 1);
		PresidentialPardonForm	form("Arthur Dent");
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	}
	std::cout << "\nCopy / Assignment Test" << std::endl;
	{
		Bureaucrat				bureaucrat("Laura", 1);
		ShrubberyCreationForm	original("original");
		bureaucrat.signForm(original);
		ShrubberyCreationForm	copyCtor(original);
		std::cout << "copy constructed form isSigned: " << copyCtor.getIsSigned() << std::endl;
		ShrubberyCreationForm	assigned("blank");
		assigned = original;
		std::cout << "assigned form isSigned: " << assigned.getIsSigned() << std::endl;
	}
	return (0);
}
