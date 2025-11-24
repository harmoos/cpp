/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:03:55 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/22 18:26:15 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() {
	this->_type = "ice";
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& other) {
	*this = other;
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

Ice* Ice::clone() const {
	return new Ice();
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
