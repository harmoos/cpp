/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 23:07:27 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/25 00:20:08 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base* generate(void) {
	srand(static_cast<unsigned int>(time(NULL)));
	int random = rand() % 3;
	if (random == 0) {
		Base* bA = new A();
		return bA;
	}
	else if (random == 1) {
		Base* bB = new B();
		return bB;
	}
	else {
		Base* bC = new C();
		return bC;
	}
	return NULL;
}

void	identify(Base* p) {
	if (dynamic_cast<A *>(p))
		std::cout << "The p is a pointer for the A class" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "The p is a pointer for the B class" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "The p is a pointer for the C class" << std::endl;
	else
		std::cout << "Type not identified" << std::endl;
}

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "The p is a pointer for the A class" << std::endl;
		return ;
	}
	catch (std::exception& e) {}

	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "The p is a pointer for the B class" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "The p is a pointer for the C class" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	std::cout << "Type not identified" << std::endl;
}

int	 main () {
	Base* base;
	(void)base;
	
	Base* base2 = generate();
	identify(base2);
	identify(*base2);
	delete base2;

	Base* base3 = NULL;
	identify(base3);
	identify(*base3);

	return 0;
}
