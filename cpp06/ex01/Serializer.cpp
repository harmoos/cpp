/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:38:29 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/24 22:58:17 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Defaut constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& other) {
	if (this != &other)
		*this = other;
}

Serializer& Serializer::operator=(const Serializer& other) {
	if (this != &other)
		*this = other;
	return *this;
}

Serializer::~Serializer() {
	std::cout << "Defaut destructor called" << std::endl;
}

uintptr_t Serializer::serializer(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

