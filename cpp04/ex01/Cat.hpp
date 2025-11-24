/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:54:33 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/22 17:21:56 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain* catBrain;
	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();
		void makeSound() const;
		Cat* clone() const;
		std::string	getIdea(int nbr);
		std::string setIdea(std::string idea, int idx);
		std::string*	getBrain();
		void	setBrain(std::string *toBrain);
		void	*getIdeaAdress(int idx);
};

#endif
