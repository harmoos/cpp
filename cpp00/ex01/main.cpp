/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:15:43 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/14 19:13:52 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	input;
	
	while (!std::cin.eof())
	{
		std::cout << "Enter a command: ";
		input.clear();
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cin.ignore();
			std::cin.clear();
			std::cout << "\nCTRL+D pressed, exiting..." << std::endl;
			break ;
		}
		std::cin.clear();
		if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
			phoneBook.displayContact();
		else if (input == "EXIT")
		{
			std::cout << "Bye byeeeee" << std::endl;
			break ;
		}
		else
			std::cout << "Invalid command, try again!" << std::endl;
	}
	return (0);
}
