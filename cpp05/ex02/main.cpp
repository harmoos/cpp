/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:35:55 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/24 16:28:00 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main (void) {
	
	try {
		Bureaucrat b1("Nath", 1);
		Bureaucrat b2("Linda", 55);
		Bureaucrat b3("Feia", 145);

		PresidentialPardonForm f3("Joao");
		f3.beSigned(b1);
		f3.toExecute(b1);

		for (int i = 0; i < 2; i++) {
			b1.decrementGrade();
		}
		for (int i = 0; i < 25; i++) {
			b2.decrementGrade();
		}
		
		std::cout << b1;
		std::cout << b2;

		ShrubberyCreationForm f1("MOI");
		f1.beSigned(b1);
		f1.toExecute(b2);

		RobotomyRequestForm f2("Hoje");
		f2.beSigned(b1);
		f2.toExecute(b1);

		b1.executeForm(f3);
		
	}
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	return (0);
}
