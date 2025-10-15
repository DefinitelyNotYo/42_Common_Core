/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:26 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/14 14:49:30 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "standard ScavTrap constructor has been called\n";
    this->set_hitPoints(100);
    this->set_energyPoints(50);
    this->set_attackDamage(20);
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap " << name << " has been created\n";
    this->set_name(name);
    this->set_hitPoints(100);
    this->set_energyPoints(50);
    this->set_attackDamage(20);    
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap has been destroyed\n"; 
}

void ScavTrap::guardGate()
{
    if(this->get_hitPoints() <= 0)
    {
        std::cout << "ScavTrap " << this->get_name() << " has " << this->get_hitPoints() 
                  << " hit points, it needs to be repaired" << std::endl;
        return ;
    }
    if(this->get_energyPoints() <= 0)
    {
        std::cout << "ScavTrap " << this->get_name() << " has not enough energy (" << this->get_energyPoints()
                  << ")" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->get_name() << " entered Gate keeper mode\n";   
}

void ScavTrap::attack(const std::string &target)
{
    if(this->get_hitPoints() <= 0)
    {
        std::cout << "ScavTrap " << this->get_name() << " has " << this->get_hitPoints() 
                  << " hit points, it needs to be repaired" << std::endl;
        return ;
    }
    if(this->get_energyPoints() <= 0)
    {
        std::cout << "ScavTrap " << this->get_name() << " has not enough energy (" << this->get_energyPoints()
                  << ")" << std::endl;
        return ;
    }
    this->set_energyPoints(this->get_energyPoints() - 1);
    std::cout << "ScavTrap " << this->get_name() << " attacks " 
              << target << ", causing " << this->get_attackDamage()
              << " points of damage!" << std::endl;
}