/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:37:47 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/13 23:32:59 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	first("Nathalia");

	first.attack("Luana");
	first.beRepaired(25);
	first.takeDamage(1000);

	return (0);
}
