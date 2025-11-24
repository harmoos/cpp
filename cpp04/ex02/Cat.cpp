/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:57:43 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/14 21:57:28 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	catBrain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) {
	*this = other;
}

Cat& Cat::operator=(const Cat& other) {
	this->type = other.type;
	return *this;
}

Cat::~Cat() {
	delete catBrain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Miau Miau" << std::endl;
}

Cat* Cat::clone() const {
	Cat* newCat = new Cat(*this);
	newCat->catBrain = new Brain(*catBrain);
	return newCat;
}

std::string*	Cat::getBrain() {
	return catBrain->getBrain();
}

void	Cat::setBrain(std::string *toBrain) {
	catBrain->setBrain(toBrain);
}

std::string	Cat::getIdea(int nbr) {
	if (nbr >= 0 && nbr < 100)
		return (catBrain->ideas[nbr]);
	else
		return ("That idea doesn't exist\n");
}
