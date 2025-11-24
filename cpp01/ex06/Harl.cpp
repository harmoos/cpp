/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:29:55 by nleoni            #+#    #+#             */
/*   Updated: 2025/03/31 21:54:29 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl; 
	std::cout << "Harl debugs" << '\n' << std::endl;
}

void	Harl::info() {
	std::cout << "[ INFO ]" << std::endl; 
	std::cout << "Harl infos" << '\n' << std::endl;
}

void	Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl; 
	std::cout << "Harl warnings" << '\n' << std::endl;
}

void	Harl::error() {
	std::cout << "[ ERROR ]" << std::endl; 
	std::cout << "Harl errors" << '\n' << std::endl;
}
	
void	Harl::complain(std::string level) {
	int	i = 0;
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*ptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	while (i < 4) {
		if (level.compare(levels[i]) == 0)
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
			(this->*ptr[0])();
			(this->*ptr[1])();
			(this->*ptr[2])();
			(this->*ptr[3])();
			break;
		
		case 1:
			(this->*ptr[1])();
			(this->*ptr[2])();
			(this->*ptr[3])();
			break;
	
		case 2:
			(this->*ptr[2])();
			(this->*ptr[3])();
			break;
	
		case 3:
			(this->*ptr[3])();
			break;
	
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
