/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:26 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/01 16:17:39 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed &Fixed::operator=(Fixed const &fpv)
{
    if (this != &fpv)
    {
        std::cout << "Copy assignment operator called" << std::endl; 
        this->fixed_point_value = fpv.getRawBits();      
    }
    return (*this);  
}

Fixed::Fixed(Fixed &value)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixed_point_value = value.getRawBits();
}

Fixed::Fixed()
{
    this->fixed_point_value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point_value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    this->fixed_point_value = raw;
}