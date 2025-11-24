/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 19:04:28 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/15 17:01:56 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	*horde;

	horde = zombieHorde(15, "Walker");
	for (int i = 0; i < 15; i++) {
		horde[i].announce();
	}
	
	delete[] horde;
	
	return (0);
}
