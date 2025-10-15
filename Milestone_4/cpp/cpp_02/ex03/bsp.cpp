/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:06:31 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/14 11:09:11 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed area(Point a, Point b, Point c)
{
    Fixed   x1(a.get_x());
    Fixed   x2(b.get_x());
	Fixed	x3(c.get_x());
    Fixed   y1(a.get_y());
    Fixed   y2(b.get_y());	
	Fixed	y3(c.get_y());
	Fixed	area((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))/2);
	if (area < 0)
		return (area * -1);
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
    Fixed	area_t = area(a, b, c);
	Fixed	area_t1 = area(p, b, c);
	Fixed	area_t2 = area(a, p, c);
	Fixed	area_t3 = area(a, b, p);
    Fixed   sum = area_t1 + area_t2 + area_t3;
	if (area_t == sum)
		return true;
	return false;
}
