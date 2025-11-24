/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:43:26 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/18 18:08:15 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "Constructor ScavTrap " << this->name << " called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	ClapTrap::operator=(other);
	this->name = other.name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructor ScavTrap " << this->name << " called!" << std::endl;
}

void ScavTrap::guardGate() {
	if (hit_points <= 0) {
		std::cout << "ScavTrap " << name << " is already dead" << std::endl;
		return ;
	}
	if (energy_points > 0)
	{
		std::cout << "ScavTrap " << this->name << " is now in gatekeeper mode!" << std::endl;
		energy_points--;
	}
	else
		std::cout << "ScavTrap " << name << " don't have enough points of energy to that" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (hit_points <= 0) {
		std::cout << "ScavTrap " << name << " is already dead" << std::endl;
		return ;
	}
	if (energy_points > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_points--;
	}
	else
		std::cout << "ScavTrap " << name << " don't have enough points of energy to attack" << std::endl;
}
