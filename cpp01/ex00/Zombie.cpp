/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:06:26 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/15 16:53:42 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName) : name(zombieName) {
	std::cout << Zombie::name << " is created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << Zombie::name << " is destroyed" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
