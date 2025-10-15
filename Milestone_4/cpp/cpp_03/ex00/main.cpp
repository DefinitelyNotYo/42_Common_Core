/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:19 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/14 13:42:59 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap lhima("Luis");
    
    lhima.attack("haribos");
    lhima.takeDamage(9);
    lhima.beRepaired(3);
    lhima.takeDamage(10);
    lhima.attack("haribos");
    return 0;
}

