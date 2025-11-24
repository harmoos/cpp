/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:52:46 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/23 23:25:28 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool sign;
		const int sign_grade;
		const int exec_grade;
	public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void	beSigned(Bureaucrat &b);
		std::string	is_signed();
		void	toExecute(Bureaucrat const& executor) const;
		virtual void	execute(Bureaucrat const& executor) const = 0;
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, AForm &f);

#endif
