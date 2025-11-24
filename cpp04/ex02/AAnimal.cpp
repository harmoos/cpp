/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:52:07 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/14 22:12:23 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
	this->type = "None";
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
	*this = other;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	this->type = other.type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
	return this->type;
}

void AAnimal::makeSound() const {
	std::cout << "None sound" << std::endl;
}
