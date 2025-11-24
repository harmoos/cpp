/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:02:58 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/15 16:52:33 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	*z1;
	
	randomChump("NewOne");
	z1 = newZombie("Walker1");
	z1->announce();
	delete z1;
	return (0);
}
