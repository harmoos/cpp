/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:13:14 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/14 19:13:38 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setContact(std::string firstN, std::string lastN, std::string nick, std::string phone, std::string darkS) {
	firstName = firstN;
	lastName = lastN;
	nickname = nick;
	phoneNumber = phone;
	darkSecret = darkS;
}

std::string	Contact::formatField(std::string field) {
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

void	Contact::display(int index) {
	std::cout << "|" << std::setw(10) << index << "|" << std::setw(10) << formatField(firstName)
			  << "|" << std::setw(10) << formatField(lastName)
			  << "|" << std::setw(10) << formatField(nickname) << "|" << std::endl;
}

void	Contact::displayIndex() {
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Dark secret: " << darkSecret << std::endl;
}
