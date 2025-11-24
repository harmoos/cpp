/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:22:28 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/16 09:02:37 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point (const Fixed n, const Fixed m) : x(n), y(m) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point &other) {
	const_cast<Fixed&>(x) = other.x;
	const_cast<Fixed&>(y) = other.y;
	return *this;
}

Point::~Point() {}

Fixed	Point::get_x() const {
	return this->x;
}

Fixed	Point::get_y() const {
	return this->y;
}
