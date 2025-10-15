/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:19 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/14 14:49:57 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap lhima("Luis");
    lhima.attack("haribos");
    lhima.guardGate();
    lhima.set_energyPoints(-42);
    lhima.attack("haribos");
    lhima.guardGate();
    return 0;
}

