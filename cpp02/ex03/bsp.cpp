/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:22:21 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/16 09:05:11 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Ax + By + C = 0

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	bool side1;
	bool side2;
	bool side3;

	side1 = ((a.get_x() - point.get_x()) * (b.get_y() - a.get_y()) - (b.get_x() - a.get_x()) * (a.get_y() - point.get_y())) > 0;
	side2 = ((b.get_x() - point.get_x()) * (c.get_y() - b.get_y()) - (c.get_x() - b.get_x()) * (b.get_y() - point.get_y())) > 0;
	side3 = ((c.get_x() - point.get_x()) * (a.get_y() - c.get_y()) - (a.get_x() - c.get_x()) * (c.get_y() - point.get_y())) > 0;

	
	if ((side1 == side2) && (side2 == side3))
		return true;
	return false;
}