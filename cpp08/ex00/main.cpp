/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:04:28 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/26 16:12:04 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

const char* NotFoundException::what() const throw() {
	return "Number not found";
}

int	main() {
	std::vector<int> array;
	int	size = 15;

	srand(static_cast<int>(time(NULL)));
	for (int i = 0; i < size; i++) {
		int	random = rand();
		array.push_back(random / 100000000);
		std::cout << array[i] << std::endl;
	}

	try {
		std::cout << "------------------------------------------------------------------" << std::endl;
		std::cout << *easyfind(array, 15) << std::endl;
		std::cout << *easyfind(array, 0) << std::endl;
		std::cout << *easyfind(array, 12) << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
