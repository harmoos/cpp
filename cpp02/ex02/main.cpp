/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:50:30 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/16 08:29:14 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "-----------------------------------------" << std::endl;
	Fixed nbr(10);
	Fixed nbr2(5);

	std::cout << nbr / nbr2 << std::endl;
	std::cout << nbr * nbr2 << std::endl;
	std::cout << nbr + nbr2 << std::endl;
	std::cout << nbr - nbr2 << std::endl;

	if (nbr >= nbr2)
		std::cout << nbr.toFloat() << " is greater or equal then " << nbr2.toFloat() << std::endl;
	if (nbr > nbr2)
		std::cout << nbr.toFloat() << " is greater then " << nbr2.toFloat() << std::endl;
	if (nbr <= nbr2)
		std::cout << nbr.toFloat() << " is smaller or equal then " << nbr2.toFloat() << std::endl;
	if (nbr < nbr2)
		std::cout << nbr.toFloat() << " is smaller then " << nbr2.toFloat() << std::endl;
	if (nbr == nbr2)
		std::cout << nbr.toFloat() << " is equal to " << nbr2.toFloat() << std::endl;
	if (nbr != nbr2)
		std::cout << nbr.toFloat() << " is different from " << nbr2.toFloat() << std::endl;

	
	return 0;
}