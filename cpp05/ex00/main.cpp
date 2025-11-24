/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:35:55 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/23 18:11:49 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main (void) {
	
	try {
		Bureaucrat b1("Nath", 1);
		Bureaucrat b2("Linda", 55);
		// Bureaucrat b3("Wrong", 152);

		for (int i = 0; i < 2; i++) {
			b1.incrementGrade();
		}
		
		for (int i = 0; i < 2; i++) {
			b1.decrementGrade();
		}
		for (int i = 0; i < 25; i++) {
			b2.decrementGrade();
		}
		
		std::cout << b1;
		std::cout << b2;

		for (int i = 0; i < 500; i++) {
			b1.decrementGrade();
		}

		std::cout << b1;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
