/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:27:46 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/11 11:34:35 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "standard WrongCat constructor has been called\n";
    type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor has been called\n";    
}

WrongCat::WrongCat(WrongCat &c)
{
    *this = c;
}

WrongCat &WrongCat::operator=(WrongCat const &value)
{
    type = value.type;
    return (*this);
}

void    WrongCat::makeSound() const
{
    std::cout << "Wrong miao\n";      
}