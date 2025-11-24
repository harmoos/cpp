/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:57:18 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/22 16:47:31 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* dogBrain;
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();
		void makeSound() const;
		Dog* clone() const;
		std::string*	getBrain();
		std::string	getIdea(int nbr);
		std::string setIdea(std::string idea, int idx);
		void	setBrain(std::string *toBrain);
		void	*getIdeaAdress(int idx);
};

#endif