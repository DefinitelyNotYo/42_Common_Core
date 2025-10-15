/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:26 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/02 10:44:53 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream &operator<<(std::ostream &os, const Fixed &value)
{
	os << value.toFloat();
	return (os);
}

Fixed &Fixed::operator=(Fixed const &fpv)
{
    if (this != &fpv)
    {
        std::cout << "Copy assignment operator called" << std::endl; 
        this->fixed_point_value = fpv.getRawBits();
    }
    return (*this);  
}

Fixed::Fixed(Fixed const &value)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = value;
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
    this->fixed_point_value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
    int i = this->fractional_bits + 1;
    this->fixed_point_value = value;
    while (--i > 0)
        this->fixed_point_value *= 2;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
    int     i = this->fractional_bits + 1;
    float   x = value;

	while (--i > 0)
		x *= 2;
	this->fixed_point_value = roundf(x);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
    return (this->fixed_point_value);
}

void Fixed::setRawBits(int const raw)
{
    this->fixed_point_value = raw;
}

float	Fixed::toFloat() const
{
	int		i = this->fractional_bits + 1;
	float	x = (float)this->fixed_point_value;

	while (--i > 0)
		x /= 2;
	return (x);
}

int		Fixed::toInt() const
{
	int		i = this->fractional_bits + 1;
	int		x = this->fixed_point_value;

	while (--i > 0)
		x /= 2;
	return (x);	
}