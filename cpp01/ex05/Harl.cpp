/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:20:38 by nleoni            #+#    #+#             */
/*   Updated: 2025/03/31 21:30:09 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug() {
	std::cout << "Harl debugs" << std::endl;
}

void	Harl::info() {
	std::cout << "Harl infos" << std::endl;
}

void	Harl::warning() {
	std::cout << "Harl warnings" << std::endl;
}

void	Harl::error() {
	std::cout << "Harl errors" << std::endl;
}

void	Harl::complain(std::string level) {
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*ptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*ptr[i])();
			return ;
		}
	}
	std::cout << "Invalid input" << std::endl;
}
