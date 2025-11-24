/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:41:52 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/19 18:59:48 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_materials[i] = 0;
	}
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		if (this->_materials[i] != 0)
			_materials[i] = other._materials[i]->clone();
		else
			_materials[i] = 0;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	for(int i = 0; i < 4; i++) {
		delete _materials[i];
		_materials[i] = 0;
	}
	for (int i = 0; i < 4; i++) {
		if (this->_materials[i] != 0)
			_materials[i] = other._materials[i]->clone();
		else
			_materials[i] = 0;
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_materials[i]) {
			delete _materials[i];
			_materials[i] = 0;
		}
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* materia) {
	for (int i = 0; i < 4; i++) {
		if (_materials[i] == 0) {
			_materials[i] = materia;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (!type.empty() && _materials[i] && _materials[i]->getType() == type)
			return (_materials[i]->clone());
	}
	return NULL;
}

