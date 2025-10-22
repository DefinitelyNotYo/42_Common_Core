/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:26 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/22 12:00:31 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "standard FragTrap constructor has been called\n";
    this->set_name("noname");
    this->set_hitPoints(100);
    this->set_energyPoints(100);
    this->set_attackDamage(30);
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap " << name << " has been created\n";
    this->set_name(name);
    this->set_hitPoints(100);
    this->set_energyPoints(100);
    this->set_attackDamage(30);    
}

FragTrap::FragTrap(FragTrap &trap)
{
    *this = trap;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap has been destroyed\n"; 
}

FragTrap &FragTrap::operator=(FragTrap const &value)
{
    if (this != &value)
    {
        ClapTrap::operator=(value);     
    }
    return (*this);
}

void FragTrap::attack(const std::string &target)
{
    if(this->get_hitPoints() <= 0)
    {
        std::cout << "FragTrap " << this->get_name() << " has " << this->get_hitPoints() 
                  << " hit points, it needs to be repaired" << std::endl;
        return ;
    }
    if(this->get_energyPoints() <= 0)
    {
        std::cout << "FragTrap " << this->get_name() << " has not enough energy (" << this->get_energyPoints()
                  << ")" << std::endl;
        return ;
    }
    this->set_energyPoints(this->get_energyPoints() - 1);
    std::cout << "FragTrap " << this->get_name() << " attacks " 
              << target << ", causing " << this->get_attackDamage()
              << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys()
{
    if(this->get_hitPoints() <= 0)
    {
        std::cout << "FragTrap " << this->get_name() << " has " << this->get_hitPoints() 
                  << " hit points, it needs to be repaired" << std::endl;
        return ;
    }
    if(this->get_energyPoints() <= 0)
    {
        std::cout << "FragTrap " << this->get_name() << " has not enough energy (" << this->get_energyPoints()
                  << ")" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->get_name() << " wants to highfive " << std::endl;
}