/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:06:35 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/14 10:57:51 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
    private:

    Fixed const x;
    Fixed const y;
    
    public:

    Point();
    Point(const float x, const float y);
    Point(Point const &value);
    ~Point();

	Point &operator=(Point const &value);

    Fixed get_x();
    Fixed get_y();
};

bool	bsp(Point const a, Point const b, Point const c, Point const p);
// Fixed	points_distance(Point a, Point b);
Fixed	area(Point a, Point b, Point c);