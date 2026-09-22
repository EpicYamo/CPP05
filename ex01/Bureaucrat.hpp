/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 16:37:54 by aaycan            #+#    #+#             */
/*   Updated: 2026/09/22 04:39:48 by aaycan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		Bureaucrat(const std::string name, int grade);

		int			getGrade() const;
		std::string	getName() const;

		void		decrementGrade();
		void		incrementGrade();

		void		signForm(Form &form);
		
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other);

#endif
