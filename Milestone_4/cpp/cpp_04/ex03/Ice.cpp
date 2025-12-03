/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:12:07 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/27 11:38:51 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
    type = "ice";
}

Ice::Ice(Ice &value)
{
    *this = value;
}


Ice::~Ice()
{
    
}

Ice &Ice::operator=(Ice const &value)
{
    (void)value;
    return (*this);
}

Ice *Ice::clone() const
{
    Ice *x = new Ice();
    return (x);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
