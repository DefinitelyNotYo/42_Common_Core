/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:37:43 by yoherfan          #+#    #+#             */
/*   Updated: 2025/09/23 09:36:45 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void    HumanA::attack()
{
    std::cout << this->name
              << " attacks with their "
              << this->w.getType()
              << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) :w(weapon)
{
    this->name = name;
}
