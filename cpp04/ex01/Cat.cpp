/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:57:43 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/22 18:39:00 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	catBrain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) {
	this->type = other.getType();
	this->catBrain = new Brain (*other.catBrain);
}

Cat& Cat::operator=(const Cat& other) {
	this->type = other.type;
	catBrain = new Brain(*other.catBrain);
	return *this;
}

Cat::~Cat() {
	delete this->catBrain;
}

void	Cat::makeSound() const {
	std::cout << "Miau Miau" << std::endl;
}

Cat* Cat::clone() const {
	Cat* newCat = new Cat(*this);
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

std::string Cat::setIdea(std::string idea, int idx) {
	if (idx < 0 || idx >= 100) {
		return ("Bad index\n");
	}
	else
		catBrain->ideas[idx] = idea;
	return ("Idea set with success!\n");
}

void	*Cat::getIdeaAdress(int idx) {
	if (idx < 0 || idx >= 100) {
		std::cout << "Bad index" << std::endl;
		return NULL;
	}
	else
		return &catBrain->ideas[idx];
}
