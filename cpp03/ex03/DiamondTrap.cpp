/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:59:15 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/19 14:42:53 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name") {}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name") {
	this->d_name = name;
	hit_points = FragTrap::hitpoints;
	energy_points = ScavTrap::energypoints;
	attack_damage = FragTrap::attackdamage;
	std::cout << "Constructor DiamondTrap " << name << " caled!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ScavTrap(other), FragTrap(other) {
	this->d_name = other.d_name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {
	FragTrap::operator=(other);
	ScavTrap::operator=(other);
	d_name = other.d_name;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Destructor DiamondTrap " << d_name << " caled!" << std::endl;
}

void	DiamondTrap::whoAmI() {
	if (hit_points <= 0) {
		std::cout << "DiamondTrap " << d_name << "is already dead" << std::endl;
		return ;
	}
	if (energy_points > 0) 
	{
		std::cout << "I am " << d_name << " from the ClapTrap named " << ClapTrap::name << std::endl;
		energy_points--;
	}
	else
		std::cout << "DiamondTrap " << d_name << " don't have enough points of energy to that" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::print(std::ostream& os) const {
	os << "DiamondTrap " << d_name << " with ClapTrap name " << ClapTrap::name << " has " << ClapTrap::hit_points << " hit_points, " << ClapTrap::energy_points << " energy_points, and " << ClapTrap::attack_damage << " attack_damage points" << std::endl;
}

std::ostream& operator<<(std::ostream& os, DiamondTrap const& d1) {
	d1.print(os);
	return os;
}
