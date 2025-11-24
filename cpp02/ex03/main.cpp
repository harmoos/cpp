/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:38:48 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/16 09:08:22 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
	Point a(0, 0);
	Point b(4, 0);
	Point c(0, 4);

	Point point1(1, 1);
	Point point2(5, 5);
	Point point3(2, 0);
	Point point4(0, 0);	
	Point point5((float)1.5, (float)1.2);
	Point point6((float)0.5, (float)1.5);
	
	std::cout << bsp(a, b, c, point1) << std::endl;
	if	(bsp(a, b, c, point1)) {
		std::cout << "The point 1 is inside the triangle" << std::endl;
	}	else {
		std::cout << "The point 1 is outside the triangle" << std::endl;
	}	
	std::cout << bsp(a, b, c, point2) << std::endl;
	if	(bsp(a, b, c, point2)) {
		std::cout << "The point 2 is inside the triangle" << std::endl;
	}	else {
		std::cout << "The point 2 is outside the triangle" << std::endl;
	}
	std::cout << bsp(a, b, c, point3) << std::endl;
	if	(bsp(a, b, c, point3)) {
		std::cout << "The point 3 is inside the triangle" << std::endl;
	}	else {
		std::cout << "The point 3 is outside the triangle" << std::endl;
	}
	std::cout << bsp(a, b, c, point4) << std::endl;
	if	(bsp(a, b, c, point4)) {
		std::cout << "The point 4 is inside the triangle" << std::endl;
	}	else {
		std::cout << "The point 4 is outside the triangle" << std::endl;
	}
	std::cout << bsp(a, b, c, point5) << std::endl;
	if	(bsp(a, b, c, point5)) {
		std::cout << "The point 5 is inside the triangle" << std::endl;
	}	else {
		std::cout << "The point 5 is outside the triangle" << std::endl;
	}
	std::cout << bsp(a, b, c, point6) << std::endl;
	if	(bsp(a, b, c, point6)) {
		std::cout << "The point 6 is inside the triangle" << std::endl;
	}	else {
		std::cout << "The point 6 is outside the triangle" << std::endl;
	}

	return 0;
}