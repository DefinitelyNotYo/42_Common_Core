/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:27:27 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/11 14:25:11 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "standard Cat constructor has been called\n";
    type = "Cat";
    brain = new Brain();
}

Cat::~Cat()
{
    delete(brain);
    std::cout << "Cat destructor has been called\n";
}

Cat::Cat(Cat &c)
{
    std::cout << "Copy Cat constructor has been called\n";
    *this = c;
}

Cat &Cat::operator=(Cat const &value)
{
    type = value.type;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Miao\n";        
}