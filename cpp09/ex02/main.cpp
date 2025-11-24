/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:07:29 by nleoni            #+#    #+#             */
/*   Updated: 2025/06/11 21:14:23 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

long jacobsthal(long n) {
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

int main(int ac, char **av) {
	if (ac < 3) {
		std::cerr << "Error: bad arguments number" << std::endl;
		return 1;
	}

	if (parse(av + 1) < 0) {
		std::cerr << "Error: not numbers or duplicates" << std::endl;
		return (1);
	}

	std::cout << "------------------------------------------------------------------------------------------------" << std::endl;

	clock_t	timeV;
	clock_t timeD;

	PmergeMe p1;

	std::cout << "Before: ";
	
	timeV = clock();
	p1.initVector(av);
	timeV = clock() - timeV;
	
	timeD = clock();
	p1.initDeque(av);
	timeD = clock() - timeD;

	std::cout << "After: ";
    printArray(p1.vector);

	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << (float)timeV * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << (float)timeD * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;
	
	std::cout << "------------------------------------------------------------------------------------------------" << std::endl;

	return 0;
}
