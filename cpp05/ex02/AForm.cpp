/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:52:38 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/23 22:49:20 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), sign(0), sign_grade(150), exec_grade(150) {
	std::cout << "Form constructor for " << _name << ", sign_grade: " << sign_grade << ", exec_grade: " << exec_grade << std::endl; 
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), sign(0), sign_grade(signGrade), exec_grade(execGrade) {
	if ((signGrade < 0 || signGrade > 150) || (execGrade < 0 || execGrade > 150)) {
		throw GradeTooLowException();
	}
	std::cout << "Form constructor for " << _name << ", sign_grade: " << sign_grade << ", exec_grade: " << exec_grade << std::endl; 
}

AForm::AForm(const AForm& other) : _name(other._name), sign(other.sign), sign_grade(other.sign_grade), exec_grade(other.exec_grade) {

}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		*this = other;
	return *this;
}

AForm::~AForm() {
	std::cout << "Form destructor called" << std::endl;
}

std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getSign() const {
	return this->sign;
}

int AForm::getSignGrade() const {
	return this->sign_grade;
}

int AForm::getExecGrade() const {
	return this->exec_grade;
}

std::string AForm::is_signed() {
	if (this->sign)
		return (" signed");
	else
		return ("n't signed");
}

void	AForm::beSigned(Bureaucrat &b) {
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

void	AForm::toExecute(Bureaucrat const& executor) const {
	if (!this->getSign()) {
		std::cout << "The form " << this->getName() << " isn't signed" << std::endl;
		throw FormNotSignedException();
	}
	if ((int)executor.getGrade() > this->getExecGrade()) {
		std::cout << "Bureaucrat " << executor.getName() << " couldn't execute " << this->getName() << " because his grade is too low" << std::endl;
		throw GradeTooLowException();
	}
	else if ((int)executor.getGrade() <= this->getExecGrade()) {
		this->execute(executor);	
	}
}

const char *AForm::GradeTooLowException::what(void) const throw() {
	return ("Error: grade too low to sign the form");
}
 
const char *AForm::GradeTooHighException::what(void) const throw() {
	return ("Error: grade too high to sign the form");
}

const char *AForm::FormNotSignedException::what(void) const throw() {
	return ("Error: the form isn't signed");
}

std::ostream &operator<<(std::ostream &os, AForm &f) {
	os << "Form " << f.getName() << " is" << f.is_signed() << " and has sign_grade: " << f.getSignGrade() << " and exec_grade: " << f.getExecGrade() << std::endl;
	return os;
}
