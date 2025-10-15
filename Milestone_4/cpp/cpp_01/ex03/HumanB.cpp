/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:37:39 by yoherfan          #+#    #+#             */
/*   Updated: 2025/09/26 15:14:22 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void    HumanB::attack()
{
    if (this->w == NULL)
    {
        return ;
    }
    std::cout << this->name
              << " attacks with their "
              << (*this->w).getType()
              << std::endl;
}

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->w = NULL;
}

void	HumanB::setWeapon(Weapon &weapon)
{
    this->w = &weapon;
}
