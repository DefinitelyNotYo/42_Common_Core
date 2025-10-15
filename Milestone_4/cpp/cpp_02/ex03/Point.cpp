/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:06:37 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/13 14:10:31 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed Point::get_x()
{
    return this->x;
}

Fixed Point::get_y()
{
    return this->y;
}

Point &Point::operator=(Point const &value)
{
    if (this != &value)
        return (*this);
    return (*this);
}

Point::Point() : x(0), y(0)
{

}
Point::Point(const float x_input, const float y_input) : x(x_input), y(y_input)
{

}

Point::Point(Point const &value) : x(value.x), y(value.y)
{

}
Point::~Point()
{

}