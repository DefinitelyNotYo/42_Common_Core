/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:19 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/14 11:12:43 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() 
{
	Point a(-2, 2);
	Point b(2, 2);
	Point c(2, -2);
	Point p(0, 2);

	if (p.get_x() != a.get_x() && p.get_x() != b.get_x() && p.get_x() != c.get_x() &&
		p.get_y() != a.get_y() && p.get_y() != b.get_y() && p.get_y() != c.get_y() &&
		bsp(a, b, c, p) == true)
		std::cout << "The point p is contained in the triangle" << std::endl;
	else
		std::cout << "The point p is NOT contained in the triangle" << std::endl;		
}
