/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:28:34 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/26 15:29:05 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main() {

	int	array[] = {1, 2, 3, 4, 42};
	iter(array, sizeof(array) / sizeof(int), printArray<int>);
	std::cout << std::endl;

	int	array2[] = {};
	iter(array2, sizeof(array2) / sizeof(int), printArray<int>);
	std::cout << std::endl;

	double	array3[] = {45.23, 96.333, 0.555, 8.6, 12};
	iter(array3, sizeof(array3) / sizeof(double), printArray<double>);
	std::cout << std::endl;

	float	array4[] = {158.0703500, 158, 56.555, 8000.6, 0.12};
	iter(array4, sizeof(array4) / sizeof(float), printArray<float>);
	std::cout << std::endl;

	std::string	array5[] = {"Hello", "je", "m'appelle", "Nathalia, ", "enchantee :)"};
	iter(array5, sizeof(array5) / sizeof(std::string), printArray<std::string>);
	std::cout << std::endl;
	
	return 0;
}
