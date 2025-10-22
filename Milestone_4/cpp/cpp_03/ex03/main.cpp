/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:19 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/22 13:00:27 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dummy("Dummy");
    dummy.attack("Enemy");
    dummy.highFivesGuys();
    dummy.whoIam();
    dummy.FragTrap::set_energyPoints(-42);
    dummy.attack("Enemy");
    dummy.highFivesGuys();
    return 0;
}

