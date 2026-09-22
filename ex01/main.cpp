/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 03:35:30 by aaycan            #+#    #+#             */
/*   Updated: 2026/09/23 01:44:05 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "Testing default constructor" << std::endl;
	Bureaucrat B_Default;
	std::cout << B_Default << '\n' << std::endl;

	std::cout << "Testing parameterized constructor" << std::endl;
	Bureaucrat B_Arda("Arda", 15);
	std::cout << B_Arda << '\n' << std::endl;

	std::cout << "Testing copy constructor" << std::endl;
	Bureaucrat B_Copy(B_Arda);
	std::cout << B_Copy << '\n' << std::endl;

	std::cout << "Testing operator overload '='" << std::endl;
	Bureaucrat B_Shinji("Shinji", 53);
	std::cout << B_Arda << std::endl;
	B_Arda = B_Shinji;
	std::cout << B_Arda << '\n' << std::endl;

	std::cout << "Testing incrementGrade & decrementGrade" << std::endl;
	Bureaucrat B_Grade("Grade", 60);
	std::cout << B_Grade << std::endl;
	B_Grade.incrementGrade();
	std::cout << B_Grade << std::endl;
	B_Grade.decrementGrade();
	B_Grade.decrementGrade();
	std::cout << B_Grade << '\n' << std::endl;

	std::cout << "Testing exceptions" << std::endl;
	Bureaucrat B_Low("Vinod", 150);
	std::cout << B_Low << std::endl;
	try
	{
		B_Low.decrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << B_Low << std::endl;
	Bureaucrat B_High("Syndic", 1);
	std::cout << B_High << std::endl;
	try
	{
		B_High.incrementGrade();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << B_High << std::endl;
	try
	{
		Bureaucrat B_Invalid_High("High", 0);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat B_Invalid_Low("Low", 151);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat B_Invalid_Too_Low("TooLow", 5302523);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat B_Invalid_Negative("Negative", -35232);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << '\n' << "Testing ex01 (Form)" << std::endl;
	std::cout << "Testing default constructor" << std::endl;
	Form default_form;
	std::cout << default_form << '\n' << std::endl;

	std::cout << "Testing parameterized constructor" << std::endl;
	Form valid_form("ValidForm", 50, 100);
	std::cout << valid_form << '\n' << std::endl;

	std::cout << "Trying to create invalid forms" << std::endl;
	try
	{
		Form invalid_form_one("inv_form_one", 0, 60);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form invalid_form_two("inv_form_one", 12, 160);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form invalid_form_three("inv_form_one", -32532523, 43643643);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form invalid_form_four("inv_form_one", 54543543, 60);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << '\n' << "Testing beSigned" << std::endl;
	Bureaucrat LowGrade("Low_Grade", 120);
	Bureaucrat HighGrade("High_Grade", 10);
	Bureaucrat SameGrade("Same_Grade", 60);
	Form test_form("test_form", 60, 60);
	std::cout << test_form << std::endl;
	test_form.beSigned(HighGrade);
	std::cout << test_form << std::endl;
	Form test_form_two("test_form_two", 60, 60);
	std::cout << test_form_two << std::endl;
	test_form_two.beSigned(SameGrade);
	std::cout << test_form_two << std::endl;
	try
	{
		test_form.beSigned(LowGrade);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << '\n' << "Testing operator overload (=)" << std::endl;
	Form another_form("AnotherForm", 80, 130);
	valid_form.beSigned(HighGrade);
	std::cout << another_form << std::endl;
	another_form = valid_form;
	std::cout << another_form << '\n' << std::endl;

	std::cout << "Testing signForm" << std::endl;
	Bureaucrat signer("Signer", 10);
	Form form_to_sign("SignMe", 50, 100);
	signer.signForm(form_to_sign);
	Bureaucrat lowGradeSigner("Low_Grade_Signer", 100);
	Form another_to_sign("CantSignMe", 50, 100);
	lowGradeSigner.signForm(another_to_sign);
	return (0);
}
