/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 03:01:02 by aaycan            #+#    #+#             */
/*   Updated: 2026/09/24 18:42:28 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const AForm &other): _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm &AForm::operator=(const AForm &other)
{
	_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm() {}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute)
	: _name(name), _isSigned(false),
	  _gradeToSign(checkGrade(gradeToSign)),
	  _gradeToExecute(checkGrade(gradeToExecute))
{}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
	{
		_isSigned = true;
		return ;
	}
	throw GradeTooLowException();
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

int AForm::checkGrade(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	if (grade > 150)
		throw AForm::GradeTooLowException();
	return (grade);
}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low for this Form");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high for this Form");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("The Form is not signed so it cannot be executed.");
}

std::ostream &operator<<(std::ostream &os,  AForm const &aform)
{
	os << "Name: " << aform.getName() << " SignStatus: " << aform.getIsSigned() << " SignGrade: " << aform.getGradeToSign() << " ExecuteGrade: " << aform.getGradeToExecute();
	return (os);
}
