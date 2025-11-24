/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:48:25 by nleoni            #+#    #+#             */
/*   Updated: 2025/03/31 20:12:00 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include "FileReplace.hpp"


int	main(int ac, char **av)
{
	if (ac != 4) {
		std::cout << "Number of arguments not good" << std::endl;
		return (1);
	}
	FileReplace	to_replace(av[1], av[2], av[3]);
	to_replace.readFile();
	
	return (0);
}
