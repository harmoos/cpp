/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:11:13 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/14 19:17:27 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void	PhoneBook::addContact() {
	std::string firstN, lastN, nick, phone, darkS;
	
	if (index >= 8) {
		index = 0;
		std::cout << "PhoneBook is full, replacing the oldest..." << std::endl;
	}
	std::cout << "First name: ";
	std::getline(std::cin, firstN);
	std::cout << "Last name: ";
	std::getline(std::cin, lastN);
	std::cout << "Nickname: ";
	std::getline(std::cin, nick);
	std::cout << "Phone number: ";
	std::getline(std::cin, phone);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, darkS);
	if (firstN.empty() || lastN.empty() || nick.empty() || phone.empty() || darkS.empty()) {
		std::cout << "Didn't get all data, try again :(" << std::endl;
		return ;
	}
	contacts[index].setContact(firstN, lastN, nick, phone, darkS);
	std::cout << "Successfully saved!" << std::endl;
	index++;
	if (totalIndex < 8)
		totalIndex++;
}
	
void	PhoneBook::displayContact() {
	int	i = 0;
	int	nbr;
	
	if (totalIndex == 0) {
		std::cout << "PhoneBook empty" << std::endl;
		return ;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	while (i < totalIndex) {
		contacts[i].display(i);
		i++;
	}
	std::cout << "---------------------------------------------" << std::endl;
	while (!std::cin.eof()) {
		std::cout << "Enter index of your choice: ";
		std::cin >> nbr;
		std::cin.ignore();
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input!" << std::endl;
			continue ;
		}
		else if (nbr < 0 || nbr >= totalIndex) {
			std::cout << "Invalid index :(" << std::endl;
			return ;
		}
		else
			break ;
	}
	if (!std::cin.eof())
		contacts[nbr].displayIndex();
}
