/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:04:09 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/26 15:40:51 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main() {
	int * a = new int(15);
	std::cout << *a << std::endl;
	
	try {
		Array<int> array;
		for (unsigned int i = 0; i < array.size(); ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
		
		
        Array<int> arr1(5);
        for (unsigned int i = 0; i < arr1.size(); ++i) {
            arr1[i] = i * 2;
        }

		Array<int> arr2 = arr1;
		Array<int> arr3;
		arr3 = arr1;
		
		for (unsigned int i = 0; i < arr1.size(); ++i) {
			std::cout << arr1[i] << " ";
		}
		std::cout << std::endl;

		std::cout << arr1[10] << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	return 0;
}
