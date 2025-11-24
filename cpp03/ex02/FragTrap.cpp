/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:38:12 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/18 18:08:58 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "Constructor FragTrap " << this->name << " called!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	ClapTrap::operator=(other);
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "Destructor FragTrap " << this->name << " called!" << std::endl;
}

void FragTrap::highFivesGuys() {
	if (hit_points <= 0) {
		std::cout << "FragTrap " << name << " is already dead" << std::endl;
		return ;
	}
	if (energy_points > 0)
	{
		std::cout << "FragTrap " << this->name << " requests a high-five!" << std::endl;
		energy_points--;
	}
	else
		std::cout << "FragTrap " << name << " don't have enough points of energy to that" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (hit_points <= 0) {
		std::cout << "FragTrap " << name << " is already dead" << std::endl;
		return ;
	}
	if (energy_points > 0)
	{
		std::cout << "FragTrap " << this->name << " attacks " << target << std::endl;
		energy_points--;
	}
	else
		std::cout << "FragTrap " << name << " don't have enough points of energy to that" << std::endl;
}
