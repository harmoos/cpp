/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:02:22 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/22 18:26:06 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {
	this->_type = "cure";
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& other) {
	*this = other;
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

Cure* Cure::clone() const {
	return new Cure();
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
