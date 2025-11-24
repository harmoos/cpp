/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:52:07 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/14 00:25:50 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	this->type = "None";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	*this = other;
}

Animal& Animal::operator=(const Animal& other) {
	this->type = other.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << "None sound" << std::endl;
}
