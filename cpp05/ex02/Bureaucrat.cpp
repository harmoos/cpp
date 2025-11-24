/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:13:18 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/23 22:44:55 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << "Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << "Constructor called for bureaucrat named " << name << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	(std::string)this->_name = other._name;
	this->_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	(std::string)this->_name = other._name;
	this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called for bureaucrat" << std::endl;
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

void	Bureaucrat::setName(Bureaucrat &other) {
	std::string newName = this->_name;
	newName = (std::string)other._name;
}

int	Bureaucrat::getGrade()const {
	return this->_grade;
}

void	Bureaucrat::incrementGrade() {
	int	tmp = (this->_grade - 1);
	if (tmp < 1)
		throw GradeTooHighException();
	else if (tmp > 150)
		throw GradeTooLowException();
	else
		this->_grade -= 1;
}

void	Bureaucrat::decrementGrade() {
	int	tmp = (this->_grade + 1);
	if (tmp < 1)
		throw GradeTooHighException();
	else if (tmp > 150)
		throw GradeTooLowException();
	else
		this->_grade += 1;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Error: grade of bureaucrat too low");
}
 
const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Error: grade of bureaucrat too high");
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &a) {
	os << a.getName() << ", bureaucrat grade " << a.getGrade() << "." << std::endl;
	return os;
}

void	Bureaucrat::signForm(AForm &f) {
	f.beSigned(*this);
}

void	Bureaucrat::executeForm(AForm const& form) {
	form.toExecute(*this);
}
