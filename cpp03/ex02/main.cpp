/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:37:47 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/18 18:13:24 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	ClapTrap	first("Nathalia");
	ScavTrap	scav("Luana");
	FragTrap	frag("Nsei");

	first.attack("Luana");
	first.beRepaired(25);
	first.takeDamage(1000);
	
	scav.attack("Nathalia");
	scav.guardGate();
	scav.beRepaired(2);

	frag.attack("Luana");
	frag.attack("Nathalia");
	first.takeDamage(30);
	frag.highFivesGuys();

	for (int i = 0; i < 100; i++) {
		frag.highFivesGuys();
	}
	
	return (0);
}
