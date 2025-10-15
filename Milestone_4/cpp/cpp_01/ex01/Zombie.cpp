/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:26 by yoherfan          #+#    #+#             */
/*   Updated: 2025/09/18 14:54:43 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    Zombie::set_name(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout << "zombie "
              << this->name
              << " has been deleted\n";
}

void	Zombie::announce()
{
    std::cout << this->name
              << ": BraiiiiiiinnnzzzZ...\n";
}
