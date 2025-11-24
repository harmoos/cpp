/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:12:58 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/23 22:48:38 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
	std::cout << "RobotomyRequestForm constructor called with target: " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) {
	this->target = other.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other)
		this->target = other.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm default destructor called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	std::cout << "Making some drilling noises" << std::endl;
	srand(static_cast<unsigned int>(time(NULL)));
	if (rand() % 2 == 1) {
		std::cout << this->target << " has been robotomized succesfully" << std::endl;
	}
	else {
		std::cout << "Robotomy failed for " << this->target << std::endl;
	}
	std::cout << "The form " << this->getName() << " was execute by " << executor.getName() << std::endl;
}