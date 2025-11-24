/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:31:59 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/15 17:18:34 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

void	Weapon::setType(std::string newType) {
	type = newType;
}

const std::string&	Weapon::getType() const {
	return (type);
}

Weapon::Weapon(std::string name) : type(name) {
	type = name;
}

Weapon::~Weapon() {}
