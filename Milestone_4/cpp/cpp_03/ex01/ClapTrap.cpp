/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:26 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/22 11:59:49 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("noname"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "standard ClapTrap constructor has been called\n";
}

ClapTrap::ClapTrap(std::string name): name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " has been created\n";
}

ClapTrap::ClapTrap(ClapTrap &trap)
{
    *this = trap;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap has been destroyed\n";
}

ClapTrap &ClapTrap::operator=(ClapTrap const &value)
{
    if (this != &value)
    {
        this->name = value.name;
        this->energyPoints = value.energyPoints;
        this->hitPoints = value.hitPoints;
        this->attackDamage = value.attackDamage;
    }
        return (*this);
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
void	ClapTrap::set_name(std::string name)
{
    this->name = name;
}
void	ClapTrap::set_hitPoints(int hitPoints)
{
    this->hitPoints = hitPoints;
}
void	ClapTrap::set_energyPoints(int energyPoints)
{
    this->energyPoints = energyPoints;
}
void	ClapTrap::set_attackDamage(int attackDamage)
{
    this->attackDamage = attackDamage;
}

std::string ClapTrap::get_name()
{
    return this->name;
}

int ClapTrap::get_hitPoints()
{
    return this->hitPoints;
}
int ClapTrap::get_energyPoints()
{
    return this->energyPoints;
}
int ClapTrap::get_attackDamage()
{
    return this->attackDamage;
}