/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 22:45:03 by aaycan            #+#    #+#             */
/*   Updated: 2026/09/23 00:57:11 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form &Form::operator=(const Form &other)
{
	_isSigned = other._isSigned;
	return (*this);
}

Form::~Form() {}

Form::Form(const std::string name, const int signGrade, const int execGrade)
	: _name(name), _isSigned(false),
	  _gradeToSign(checkGrade(signGrade)),
	  _gradeToExecute(checkGrade(execGrade))
{}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
	{
		_isSigned = true;
		return ;
	}
	throw GradeTooLowException();
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low for this form");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high for this form");
}

std::ostream &operator<<(std::ostream &os,  Form const &form)
{
	os << "Name: " << form.getName() << " SignStatus: " << form.getIsSigned() << " SignGrade: " << form.getGradeToSign() << " ExecuteGrade: " << form.getGradeToExecute();
	return (os);
}

int Form::checkGrade(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
	return (grade);
}
