/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:43:33 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/26 22:55:39 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try {
		Span sp = Span(5);
	
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << "________________________________________________" << std::endl;

		unsigned int sizeTotal = 15000;
		Span sp2 = Span(sizeTotal);
		
		srand(static_cast<unsigned int>(time(NULL)));
		for (unsigned int i = 0; i < sizeTotal; i++) {
			int random = rand() / 1000000;
			sp2.addNumber(random);
			// std::cout << "Span[" << i << "]: " << sp2.getArrayAt(i) << std::endl;
		}

		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;

		std::cout << "________________________________________________" << std::endl;
		
		std::vector<int> toInsert;
		unsigned int totalSize = 4294967;
		Span sp3 = Span(totalSize);

		for (unsigned int i = 0; i < totalSize; i++) {
			int random = rand() / 1000;
			toInsert.push_back(random);
		}

		sp3.addNumber(toInsert.begin(), toInsert.end());

		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;

		std::cout << "________________________________________________" << std::endl;

		Span sp4 = Span();

		std::cout << sp4.shortestSpan() << std::endl;

	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	return 0;
}
