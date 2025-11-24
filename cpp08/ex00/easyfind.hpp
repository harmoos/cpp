/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:05:26 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/26 14:35:51 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <ctime>
#include <cstdlib>
#include <algorithm>

template <typename T> 
typename T::iterator easyfind(T &container, int nbr);

class NotFoundException : public std::exception {
	public:
		virtual const char *what() const throw();
};

#include "easyfind.tpp"

#endif
