/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:03:03 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/15 16:54:09 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie(std::string zombieName);
		~Zombie();
		void	announce(void);
	};
	
void	randomChump(std::string name);
Zombie*	newZombie(std::string name);
	
#endif