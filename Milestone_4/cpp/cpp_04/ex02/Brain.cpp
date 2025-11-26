/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:01:24 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/11 14:11:04 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "standard Brain constructor has been called\n";    
}

Brain::Brain(Brain &b)
{
    std::cout << "Copy Brain constructor has been called\n";
    *this = b;
}

Brain::~Brain()
{
    std::cout << "Brain destructor has been called\n";       
}

Brain &Brain::operator=(Brain const &value)
{
    int i = -1;
    while (++i < 100)
        this->ideas[i] = value.ideas[i];
    return (*this);
}