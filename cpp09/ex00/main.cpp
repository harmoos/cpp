/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:41:06 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/28 23:58:08 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	try {
		if (ac != 2)
			throw BitcoinExchange::FileNotOpenException();
		BitcoinExchange b1(av[1]);
		b1.compareDatas();
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
   return 0;
		return 0;
}
