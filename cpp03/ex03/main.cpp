/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:37:47 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/19 14:33:19 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void) {
	// ClapTrap	first("Nathalia");
	// ScavTrap	scav("Luana");
	// FragTrap	frag("Nsei");
	DiamondTrap diamond("Gold");

	// first.attack("Luana");
	// first.beRepaired(25);
	// first.takeDamage(1000);
	
	// scav.attack("Nathalia");
	// scav.guardGate();
	// scav.beRepaired(2);

	// frag.attack("Luana");
	// frag.attack("Nathalia");
	// first.takeDamage(30);
	// frag.highFivesGuys();
	
	std::cout << diamond;
	diamond.attack("Prata");
	std::cout << diamond;
	diamond.whoAmI();
	std::cout << diamond;
	diamond.guardGate();
	std::cout << diamond;
	diamond.takeDamage(40);
	std::cout << diamond;
	diamond.beRepaired(30);
	std::cout << diamond;

	
	return (0);
}
