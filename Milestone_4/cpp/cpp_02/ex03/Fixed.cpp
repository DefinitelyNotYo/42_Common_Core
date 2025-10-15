/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:26 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/14 09:30:12 by yoherfan         ###   ########.fr       */
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
        // std::cout << "Copy assignment operator called" << std::endl; 
        this->fixed_point_value = fpv.getRawBits();
    }
    return (*this);  
}

Fixed	Fixed::operator+(Fixed const &fpv)
{
	return (Fixed(this->toFloat() + fpv.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &fpv)
{
	return (Fixed(this->toFloat() - fpv.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &fpv)
{
	return (Fixed(this->toFloat() * fpv.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &fpv)
{
	return (Fixed(this->toFloat() / fpv.toFloat()));
}

bool	Fixed::operator>(Fixed const &fpv)
{
	if (this->fixed_point_value > fpv.fixed_point_value)
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const &fpv)
{
	if (this->fixed_point_value < fpv.fixed_point_value)
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &fpv)
{
	if (this->fixed_point_value >= fpv.fixed_point_value)
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &fpv)
{
	if (this->fixed_point_value <= fpv.fixed_point_value)
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &fpv)
{
	if (this->fixed_point_value == fpv.fixed_point_value)
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &fpv)
{
	if (this->fixed_point_value != fpv.fixed_point_value)
		return (true);
	return (false);
}

Fixed	&Fixed::operator++()
{
	++this->fixed_point_value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed x(*this);
	this->fixed_point_value++;
	return (x);
}

Fixed	&Fixed::operator--()
{
	--this->fixed_point_value;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed x(*this);
	this->fixed_point_value--;
	return (x);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.fixed_point_value < b.fixed_point_value)
		return (a);
	else
		return (b);
}

Fixed	const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.fixed_point_value < b.fixed_point_value)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.fixed_point_value > b.fixed_point_value)
		return (a);
	else
		return (b);
}

Fixed	const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.fixed_point_value > b.fixed_point_value)
		return (a);
	else
		return (b);
}

Fixed::Fixed(Fixed const &value)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = value;
}

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
    this->fixed_point_value = 0;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
    int i = this->fractional_bits + 1;
    this->fixed_point_value = value;
    while (--i > 0)
        this->fixed_point_value *= 2;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
    int     i = this->fractional_bits + 1;
    float   x = value;

	while (--i > 0)
		x *= 2;
	this->fixed_point_value = roundf(x);
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called\n";
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