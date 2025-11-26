/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:27:33 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/11 14:34:42 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "standard Dog constructor has been called\n";
    type = "Dog";
    brain = new Brain();
}

Dog::~Dog()
{
    delete(brain); 
    std::cout << "Dog destructor has been called\n";
}

Dog::Dog(Dog &c)
{
    std::cout << "Copy Dog constructor has been called\n";
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