/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:00:01 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/23 23:25:47 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	if (this != &other)
		*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	if (this != &other)
		*this = other;
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(std::string formName, std::string target) {
	std::string forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 0;
	while (i < 3 && formName != forms[i])
		i++;
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << forms[i] << std::endl;
			return new ShrubberyCreationForm(target);
			break;
		
		case 1:
			std::cout << "Intern creates " << forms[i] << std::endl;
			return new RobotomyRequestForm(target);
			break;

		case 2:
			std::cout << "Intern creates " << forms[i] << std::endl;
			return new PresidentialPardonForm(target);
			break;
		
		default:
			std::cout << formName << " form don't exist" << std::endl;
			throw FormNotCreatedException(); 
			break;
	}
}

const char *Intern::FormNotCreatedException::what(void) const throw() {
	return ("Intern said that this form doesn't exist");
}
