/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:42:36 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/22 17:57:03 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++) {
		this->ideas[i].empty();		
	}
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain& other) {
	std::string *newIdeas = other.getBrain();
	for (int i = 0; i < 100; i++) {
		ideas[i] = newIdeas[i];
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
	return this->ideas;
}

void	Brain::setBrain(std::string toBrain[100]) {
	for (int i = 0; i < 100; i++) {
		if (!toBrain[i].empty())
			ideas[i] = toBrain[i];
	}
}
