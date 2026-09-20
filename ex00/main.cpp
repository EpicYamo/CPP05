/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 03:35:30 by aaycan            #+#    #+#             */
/*   Updated: 2026/09/20 05:26:24 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "Testing default constructor" << std::endl;
	Bureaucrat B_Default;
	std::cout << B_Default << '\n' << std::endl;

	std::cout << "Testing operator overload '<<'" << std::endl;
	Bureaucrat B_Arda("Arda", 15);
	std::cout << B_Arda << '\n' << std::endl;

	std::cout << "Testing copy constructor" << std::endl;
	Bureaucrat B_Copy(B_Arda);
	std::cout << B_Copy << '\n' << std::endl;

	std::cout << "Testing operator overload '='" << std::endl;
	Bureaucrat B_Shinji("Shinji", 53);
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
	return (0);
}