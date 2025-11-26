/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:27:38 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/11 11:45:52 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "standard WrongAnimal constructor has been called\n";
    type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor has been called\n";    
}

WrongAnimal::WrongAnimal(WrongAnimal &a)
{
    *this = a;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &value)
{
    type = value.type;
    return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "Generic wrong animal sound\n";        
}

std::string  WrongAnimal::getType() const
{
    return (this->type);
}