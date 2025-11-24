/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:42:36 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/14 21:16:31 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	*this = other;
	for (int i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other) {
	for (int i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

std::string*	Brain::getBrain() {
	return ideas;
}

void	Brain::setBrain(std::string toBrain[100]) {
	for (int i = 0; i < 100; i++) {
		ideas[i] = toBrain[i];
	}
}
