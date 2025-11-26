/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:27:23 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/11 14:49:46 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "standard Animal constructor has been called\n";
    type = "Animal";
}

Animal::~Animal()
{
    std::cout << "Animal destructor has been called\n";    
}

Animal::Animal(Animal &a)
{
    std::cout << "Copy Animal constructor has been called\n";
    *this = a;
}

Animal &Animal::operator=(Animal const &value)
{
    type = value.type;
    return (*this);
}

void Animal::makeSound() const
{
    std::cout << "Generic animal sound\n";        
}

std::string  Animal::getType() const
{
    return (this->type);
}