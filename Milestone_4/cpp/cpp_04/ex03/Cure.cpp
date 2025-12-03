/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:11:50 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/27 12:05:27 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
    type = "cure";
}

Cure::Cure(Cure &value)
{
    *this = value;
}


Cure::~Cure()
{
    
}

Cure &Cure::operator=(Cure const &value)
{
    (void)value;
    return (*this);
}

Cure *Cure::clone() const
{
    Cure *x = new Cure();
    return (x);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}