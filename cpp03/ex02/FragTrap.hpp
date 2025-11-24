/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 21:37:48 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/13 22:57:50 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(const std::string& name);
    	FragTrap(const FragTrap& other);
    	FragTrap& operator=(const FragTrap& other);
    	~FragTrap();
		void attack(const std::string& target);
    	void highFivesGuys();
};

#endif