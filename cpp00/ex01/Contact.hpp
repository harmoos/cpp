/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:16:05 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/14 19:13:03 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

class Contact
{
	private:
		std::string	phoneNumber;
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	darkSecret;

	public:
		void	setContact(std::string firstN, std::string lastN, std::string nick, std::string phone, std::string darkS);
		std::string formatField(std::string field);
		void	display(int index);
		void	displayIndex();

	Contact() {}
};




#endif