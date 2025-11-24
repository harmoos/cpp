/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:50:45 by nleoni            #+#    #+#             */
/*   Updated: 2025/05/02 17:31:04 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main (int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: bad arguments number" << std::endl;
		return 0;
	}
	RPN	r1 = RPN(av[1]);
	r1.calculate();
}