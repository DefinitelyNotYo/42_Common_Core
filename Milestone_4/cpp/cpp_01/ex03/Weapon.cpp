/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:37:31 by yoherfan          #+#    #+#             */
/*   Updated: 2025/09/26 15:17:20 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string const   &Weapon::getType()
{
    return (this->type);
}

void    Weapon::setType(std::string const name)
{
    this->type = name;
}

Weapon::Weapon(std::string weapon)
{
    this->type = weapon;
}

Weapon::Weapon()
{
    
}
