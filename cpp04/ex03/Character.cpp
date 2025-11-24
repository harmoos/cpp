/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 00:25:31 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/22 18:47:01 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("") {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = 0;
	}
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = 0;
	}
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character& other) : _name(other._name) {
	for(int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		this->_inventory[i] = 0;
	}
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i] != 0)
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = 0;
	}
}

Character& Character::operator=(const Character& other) {
	
	for(int i = 0; i < 4; i++) {
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		this->_inventory[i] = 0;
	}
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] != 0)
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = 0;
	}
	_name = other._name;
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
		_inventory[i] = 0;
	}
	std::cout << "Character destructor called" << std::endl;
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (m == 0) {
		std::cout << "Cannot equip a NULL materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == 0) {
			_inventory[i] = m;
			std::cout << "Inventory of " << _name << " at index " << i << " is equipped with " << m->getType() << std::endl;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3) {
		if (_inventory[idx] != 0) {
			std::cout << _name << " let drop his " << _inventory[idx]->getType() << std::endl;
			_inventory[idx] = 0;
		}
		else
			std::cout << "There's no materia at index " << idx << " in the inventory of " << _name << std::endl;	
		return ;
	}
	else {
		std::cout << "Index of inventory invalid" << std::endl;
		return ;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx <= 3) {
		if (_inventory[idx] != 0) {
			_inventory[idx]->use(target);
		}
		else
			std::cout << "There's no materia at " << idx << " in the inventory of " << _name << std::endl;	
		return ;
	}
	else {
		std::cout << "Index of inventory invalid" << std::endl;
		return ;
	}
}

AMateria* Character::getMateria(int idx) const {
	if (idx >= 0 && idx <= 3) {
		if (_inventory[idx] != 0) {
			return _inventory[idx];
		}
		else
			std::cout << "There's no materia at " << idx << " in the inventory of " << _name << std::endl;	
		return NULL;
	}
	else {
		std::cout << "Index of inventory invalid" << std::endl;
		return NULL;
	}
}
