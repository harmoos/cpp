/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:11:53 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/14 19:12:43 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		index;
		int		totalIndex;

	public:
		PhoneBook() : index(0), totalIndex(0) {}
		void	addContact();	
		void	displayContact();
	
};

#endif
