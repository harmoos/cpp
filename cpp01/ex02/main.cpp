/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 19:52:39 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/15 17:08:19 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << "Memory address of the string: " << &brain << std::endl; 
	std::cout << "Memory address of strngPTR: " << stringPTR << std::endl; 
	std::cout << "Memory address of stringREF: " << &stringREF << std::endl; 
	std::cout << "Value of the string: " << brain << std::endl; 
	std::cout << "Value of of strngPTR: " << *stringPTR << std::endl; 
	std::cout << "Value of of stringREF: " << stringREF << std::endl; 
	return (0);
}

