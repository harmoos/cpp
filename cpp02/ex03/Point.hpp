/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:22:39 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/16 09:02:48 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <limits>
#include <cmath>
#include "Fixed.hpp"

class Point {
	private:
		Fixed const x;
		Fixed const y;
		
	public:
		Point();
		Point (const Fixed n, const Fixed m);
		Point(const Point& other);
		Point& operator=(const Point &other);
		~Point();
		Fixed	get_y() const;
		Fixed	get_x() const;
};
	
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
