/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:26 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/14 13:48:10 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "standard constructor has been called\n";
    this->attackDamage = 0;
    this->energyPoints = 10;
    this->hitPoints = 10;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap " << name << " has been created\n";
    this->name = name;
    this->attackDamage = 0;
    this->energyPoints = 10;
    this->hitPoints = 10;
}

ClapTrap::~ClapTrap()
{
    std::cout << "destructor has been called\n";
}

void ClapTrap::attack(const std::string &target)
{
    if(this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " has " << this->hitPoints 
                  << " hit points, it needs to be repaired" << std::endl;
        return ;
    }
    if(this->energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " has not enough energy (" << this->energyPoints
                  << ")" << std::endl;
        return ;
    }
    this->energyPoints -= 1; 
    std::cout << "ClapTrap " << this->name << " attacks " 
              << target << ", causing " << this->attackDamage
              << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name << " has been hitted for " 
              << amount << " points of damage!" << std::endl;
    this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " has " << this->hitPoints 
                  << " hit points, it needs to be repaired" << std::endl;
        return ;
    }
    if(this->energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " has not enough energy (" << this->energyPoints
                  << ")" << std::endl;
        return ;
    }
    this->energyPoints -= 1;    
    std::cout << "ClapTrap " << this->name << " heals itself for " 
              << amount << " hp!" << std::endl;
    this->hitPoints += amount;
}
