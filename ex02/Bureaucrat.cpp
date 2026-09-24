/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 03:16:22 by aaycan            #+#    #+#             */
/*   Updated: 2026/09/24 05:04:29 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	_grade = other._grade;	
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{	
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		_grade = grade;
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

void Bureaucrat::decrementGrade()
{
	if (_grade != 150)
		_grade++;
	else
		throw GradeTooLowException();
}

void Bureaucrat::incrementGrade()
{
	if (_grade != 1)
		_grade--;
	else
		throw GradeTooHighException();
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (os);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low for this bureaucrat");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high for this bureaucrat");
}

void Bureaucrat::signForm(AForm &aform)
{
	try
	{
		aform.beSigned(*this);
	}
	catch(const std::exception &e)
	{
		std::cout << _name << " couldn't sign " << aform.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << _name << " signed " << aform.getName() << std::endl;
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
	}
	catch (const std::exception &e)
	{
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << _name << " executed " << form.getName() << std::endl;
}
