/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:38:37 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/24 22:58:05 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Serializer {
	private:
		Serializer();
	public:
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();
		static uintptr_t serializer(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
