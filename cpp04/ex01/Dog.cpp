/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:00:58 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/22 18:02:55 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	dogBrain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) {
	this->type = other.getType();
	dogBrain = new Brain(*other.dogBrain);
}

Dog& Dog::operator=(const Dog& other) {
	this->type = other.type;
	dogBrain = new Brain(*other.dogBrain);
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

std::string Dog::setIdea(std::string idea, int idx) {
	if (idx < 0 || idx >= 100) {
		return ("Bad index\n");
	}
	else
		dogBrain->ideas[idx] = idea;
	return ("Idea set with success!\n");
}

void	*Dog::getIdeaAdress(int idx) {
	if (idx < 0 || idx >= 100) {
		std::cout << "Bad index" << std::endl;
		return NULL;
	}
	else
		return &dogBrain->ideas[idx];
}
