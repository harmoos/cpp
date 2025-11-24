/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:00:58 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/14 21:56:38 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	dogBrain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) {
	*this = other;
}

Dog& Dog::operator=(const Dog& other) {
	this->type = other.type;
	return *this;
}

Dog::~Dog() {
	delete dogBrain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Au Au" << std::endl;
}

Dog* Dog::clone() const {
	Dog* newDog = new Dog(*this);
	newDog->dogBrain = new Brain(*dogBrain);
	return newDog;
}

std::string*	Dog::getBrain() {
	return dogBrain->getBrain();
}

void	Dog::setBrain(std::string *toBrain) {
	dogBrain->setBrain(toBrain);
}

std::string	Dog::getIdea(int nbr) {
	if (nbr >= 0 && nbr < 100)
		return (dogBrain->ideas[nbr]);
	else
		return ("That idea doesn't exist\n");
}
