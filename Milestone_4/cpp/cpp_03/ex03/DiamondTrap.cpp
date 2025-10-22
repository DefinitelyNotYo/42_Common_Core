/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:11:54 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/22 14:10:43 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    std::cout << "standard DiamondTrap constructor has been called\n";
    ClapTrap::set_name("noname");
    clapName = FragTrap::get_name() + "_clap_name";
    FragTrap::set_hitPoints(100);
    ScavTrap::set_hitPoints(50);
    FragTrap::set_attackDamage(30);
}

DiamondTrap::DiamondTrap(std::string name)
{
    std::cout << "DiamondTrap " << name << " has been created\n";
    ScavTrap::set_name(name);
    clapName = FragTrap::get_name() + "_clap_name";
    FragTrap::set_hitPoints(100);
    ScavTrap::set_hitPoints(50);
    FragTrap::set_attackDamage(30);
}

DiamondTrap::DiamondTrap(DiamondTrap &trap)
{
    *this = trap;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << ClapTrap::get_name() << " has been destroyed\n"; 
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &value)
{
    if (this != &value)
    {
        ClapTrap::operator=(value);    
    }
    return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoIam()
{
    if(FragTrap::get_hitPoints() <= 0)
    {
        std::cout << "DiamondTrap " << ClapTrap::get_name() << " has " << ClapTrap::get_hitPoints() 
                  << " hit points, it needs to be repaired" << std::endl;
        return ;
    }
    if(ClapTrap::get_energyPoints() <= 0)
    {
        std::cout << "DiamondTrap " << ClapTrap::get_name() << " has not enough energy (" << ClapTrap::get_energyPoints()
                  << ")" << std::endl;
        return ;
    }
    std::cout << "name: " << ClapTrap::get_name() << std::endl
              << "clap name: " << clapName << std::endl;
}