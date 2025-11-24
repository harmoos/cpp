/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:52:46 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/24 16:24:22 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool sign;
		const int sign_grade;
		const int exec_grade;
	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string getName();
		bool getSign();
		int getSignGrade();
		int getExecGrade();

		void	beSigned(Bureaucrat &b);
		std::string	is_signed();
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Form &f);

#endif
