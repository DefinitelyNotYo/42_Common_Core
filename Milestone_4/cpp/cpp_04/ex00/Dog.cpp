/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:27:33 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/11 11:26:54 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "standard Dog constructor has been called\n";
    type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Dog destructor has been called\n";    
}

Dog::Dog(Dog &c)
{
    *this = c;
}

Dog &Dog::operator=(Dog const &value)
{
    type = value.type;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Bau\n";        
}