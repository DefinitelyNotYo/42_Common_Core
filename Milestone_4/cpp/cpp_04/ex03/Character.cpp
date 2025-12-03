/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:30:01 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/03 09:51:42 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    floor_pin = 0;
    inventory[0] = NULL;
    inventory[1] = NULL;
    inventory[2] = NULL;
    inventory[3] = NULL;
    floor[0] = NULL;
    floor[1] = NULL;
    floor[2] = NULL;
    floor[3] = NULL;
}

Character::Character(Character &c)
{
    name = c.name;
    floor_pin = c.floor_pin;
    inventory[0] = c.inventory[0];
    inventory[1] = c.inventory[1];
    inventory[2] = c.inventory[2];
    inventory[3] = c.inventory[3];
    floor[0] = c.floor[0];
    floor[1] = c.floor[1];
    floor[2] = c.floor[2];
    floor[3] = c.floor[3];
}

Character::Character(std::string n)
{
    name = n;
    floor_pin = 0;
    inventory[0] = NULL;
    inventory[1] = NULL;
    inventory[2] = NULL;
    inventory[3] = NULL;
    floor[0] = NULL;
    floor[1] = NULL;
    floor[2] = NULL;
    floor[3] = NULL;
}

Character::~Character()
{
    int i = -1;
    while(++i < 4)
    {
        if (inventory[i])
            delete inventory[i];
    }
    i = -1;
    while(++i < 4)
    {
        if (floor[i])
            delete floor[i];
    }    
}

Character &Character::operator=(Character const &value)
{
    name = value.name;
    floor_pin = value.floor_pin;
    inventory[0] = value.inventory[0];
    inventory[1] = value.inventory[1];
    inventory[2] = value.inventory[2];
    inventory[3] = value.inventory[3];
    floor[0] = value.floor[0];
    floor[1] = value.floor[1];
    floor[2] = value.floor[2];
    floor[3] = value.floor[3];
    return (*this);
}

std::string const &Character::getName() const
{
    return (name);
}

void Character::getInventory() const
{
    int i = -1;
    while (++i < 4)
    {
        if(inventory[i])
            std::cout << inventory[i]->getType() << std::endl;        
    }
}

void Character::equip(AMateria* m)
{
    int i = -1;
    while (++i < 4)
    {
        if (inventory[i] == m)
            return ;
        if (inventory[i] == NULL)
        { 
            inventory[i] = m;
            return ;
        }        
    }
    return ;
}

void Character::unequip(int idx)
{
    if (idx > 3 || idx < 0)
        return ;
    if (inventory[idx] == NULL)
        return ;
    if (floor[floor_pin] != NULL)
        delete(floor[floor_pin]);
    floor[floor_pin] = inventory[idx];
    inventory[idx] = NULL;
    if (floor_pin == 9)
        floor_pin = 0;
    else
        floor_pin++;
}

void Character::use(int idx, ICharacter& target)
{
    if(idx > 3 || idx < 0)
        return ;
    if (inventory[idx] == NULL)
        return ;
    this->inventory[idx]->use(target);
}
