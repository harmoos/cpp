/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:12:11 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/18 18:05:57 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hit_points(0), energy_points(0), attack_damage(0) {}

ClapTrap::ClapTrap(std::string name) {
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "Constructor ClapTrap " << name << " called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->attack_damage = other.attack_damage;
	this->energy_points = other.energy_points;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->attack_damage = other.attack_damage;
	this->energy_points = other.energy_points;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor ClapTrap " << name << " called!" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (hit_points <= 0) {
		std::cout << "ClapTrap " << name << " is already dead" << std::endl;
		return ;
	}
	if (energy_points > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_points--;
	}
	else
		std::cout << "ClapTrap " << name << " don't have enough points of energy to attack" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (hit_points > 0) {
		hit_points -= amount;
		std::cout << "ClapTrap " << name << " took " << amount << " points of damage!" << std::endl;
	}
	if (hit_points <= 0) {
		std::cout << "ClapTrap " << name << " is already dead" << std::endl;
		return ;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (hit_points <= 0) {
		std::cout << "ClapTrap " << name << " is already dead" << std::endl;
		return ;
	}
	if (energy_points > 0) 
	{
		hit_points += amount;
		std::cout << "ClapTrap " << name << " is beign repaired of " << amount << " hit points!" << std::endl;
		energy_points--;
	}
	else
		std::cout << "ClapTrap " << name << " don't have enough points of energy to be repaired" << std::endl;
}

