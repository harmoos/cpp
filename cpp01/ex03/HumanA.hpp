/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:17:14 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/15 17:09:54 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class	HumanA {
	private:
		std::string	name;
		Weapon	&weapon;
	
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void	attack();
	
};

#endif
