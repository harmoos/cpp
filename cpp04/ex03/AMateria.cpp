/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:58:49 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/15 18:20:31 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) {
	*this = other;
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other)
		this->_type = other._type;
	return *this;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) {
	this->_type = type;
}

const std::string& AMateria::getType() const {
	return _type;
}

void	AMateria::use(ICharacter& target) {
	std::cout << "Using " << _type << " materia at " << target.getName() << std::endl;
}
