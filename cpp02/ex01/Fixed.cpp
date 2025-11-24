/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:06:36 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/16 08:14:45 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed_nbr(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->fixed_nbr = value << fractional;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->fixed_nbr = roundf(value * (1 << fractional));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	fixed_nbr = other.fixed_nbr;
}

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_nbr = other.fixed_nbr;
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return fixed_nbr;
}

void	Fixed::setRawBits(int const raw) {
	fixed_nbr = raw;
}

float	Fixed::toFloat() const {
	return static_cast<float>(fixed_nbr) / (1 << fractional);
}

int	Fixed::toInt() const {
	return fixed_nbr >> fractional;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
