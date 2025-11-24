/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:35:55 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/23 19:41:59 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main (void) {
	
	try {
		Bureaucrat b1("Nath", 1);
		Bureaucrat b2("Linda", 55);
		// Bureaucrat b3("Wrong", 152);

		// for (int i = 0; i < 2; i++) {
		// 	b1.incrementGrade();
		// }
		
		for (int i = 0; i < 2; i++) {
			b1.decrementGrade();
		}
		for (int i = 0; i < 25; i++) {
			b2.decrementGrade();
		}
		
		std::cout << b1;
		std::cout << b2;

		// for (int i = 0; i < 500; i++) {
		// 	b1.decrementGrade();
		// }

		// std::cout << b1;

		Form f1("FirstForm", 100, 20);
		
		std::cout << f1;

		f1.beSigned(b1);
		f1.beSigned(b2);

		std::cout << f1;
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	return (0);
}
