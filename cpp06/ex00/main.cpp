/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:43:25 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/24 19:01:05 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Bad arguments!" << std::endl;
		return (1);
	}
	
	ScalarConverter::convert(av[1]);
	
	return (0);
}
