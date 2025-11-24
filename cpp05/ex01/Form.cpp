/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:52:38 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/23 19:41:38 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), sign(0), sign_grade(150), exec_grade(150) {
	std::cout << "Form constructor for " << _name << ", sign_grade: " << sign_grade << ", exec_grade: " << exec_grade << std::endl; 
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), sign(0), sign_grade(signGrade), exec_grade(execGrade) {
	if ((signGrade < 0 || signGrade > 150) || (execGrade < 0 || execGrade > 150)) {
		throw GradeTooLowException();
	}
	std::cout << "Form constructor for " << _name << ", sign_grade: " << sign_grade << ", exec_grade: " << exec_grade << std::endl; 
}

Form::Form(const Form& other) : _name(other._name), sign(other.sign), sign_grade(other.sign_grade), exec_grade(other.exec_grade) {

}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		*this = other;
	return *this;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() {
	return this->_name;
}

bool Form::getSign() {
	return this->sign;
}

int Form::getSignGrade() {
	return this->sign_grade;
}

int Form::getExecGrade() {
	return this->exec_grade;
}

std::string Form::is_signed() {
	if (this->sign)
		return (" signed");
	else
		return ("n't signed");
}

void	Form::beSigned(Bureaucrat &b) {
	if (this->sign) {
		std::cout << "The form is already signed" << std::endl;
		return ;
	}
	if (b.getGrade() <= this->sign_grade) {
		this->sign = true;
		std::cout << "The form " << this->_name << " is signed by " << b.getName() << std::endl;
	}
	else {
		std::cout << "Bureaucrat " << b.getName() << " couldn't sign " << this->getName() << " because his grade is too low" << std::endl;
		throw GradeTooLowException();
	}
}

const char *Form::GradeTooLowException::what(void) const throw() {
	return ("Error: grade too low to sign the form");
}
 
const char *Form::GradeTooHighException::what(void) const throw() {
	return ("Error: grade too high to sign the form");
}

std::ostream &operator<<(std::ostream &os, Form &f) {
	os << "Form " << f.getName() << " is" << f.is_signed() << " and has sign_grade: " << f.getSignGrade() << " and exec_grade: " << f.getExecGrade() << std::endl;
	return os;
}
