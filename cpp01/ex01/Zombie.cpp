/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:53:58 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/15 17:04:22 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie::Zombie(std::string zombieName) : _name(zombieName) {
	std::cout << Zombie::_name << " is created" << std::endl;
}

Zombie::~Zombie() {
}

void	Zombie::announce(void) {
	std::cout << Zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

