/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:21:44 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/16 08:30:48 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <limits>

class	Fixed {
	private:
		int	fixed_nbr;
		static const int	fractional = 8;
	
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed &other);
		~Fixed();
		
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
		bool operator<(const Fixed& n1) const;
		bool operator>(const Fixed& n1) const;
		bool operator>=(const Fixed& n1) const;
		bool operator<=(const Fixed& n1) const;
		bool operator==(const Fixed& n1) const;
		bool operator!=(const Fixed& n1) const;
		
		Fixed operator+(const Fixed& n1) const;
		Fixed operator-(const Fixed& n1) const;
		Fixed operator*(const Fixed& n1) const;
		Fixed operator/(const Fixed& n1) const;
		
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);
		
		static Fixed& min(Fixed& n1, Fixed& n2);
		const static Fixed& min(const Fixed& n1, const Fixed& n2);
		static Fixed& max(Fixed& n1, Fixed& n2);
		const static Fixed& max(const Fixed& n1, const Fixed& n2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif