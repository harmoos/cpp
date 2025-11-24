/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:20:35 by nleoni            #+#    #+#             */
/*   Updated: 2025/03/31 21:13:15 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class	Harl {
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		
	public:
		void	complain(std::string level);
};

#endif
