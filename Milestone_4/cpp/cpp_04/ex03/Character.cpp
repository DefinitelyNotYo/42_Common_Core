/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:30:01 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/13 14:42:47 by yoherfan         ###   ########.fr       */
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
}

Character::Character(Character &c)
{
    name = c.name;
    floor_pin = c.floor_pin;
    inventory[0] = c.inventory[0];
    inventory[1] = c.inventory[1];
    inventory[2] = c.inventory[2];
    inventory[3] = c.inventory[3];
}

Character::Character(std::string n)
{
    name = n;
    floor_pin = 0;
    inventory[0] = NULL;
    inventory[1] = NULL;
    inventory[2] = NULL;
    inventory[3] = NULL;
}

Character::~Character()
{
    
}

Character &Character::operator=(Character const &value)
{
    name = value.name;
    floor_pin = value.floor_pin;
    inventory[0] = value.inventory[0];
    inventory[1] = value.inventory[1];
    inventory[2] = value.inventory[2];
    inventory[3] = value.inventory[3];
    return (*this);
}

std::string const &Character::getName() const
{
    return (name);
}

void Character::equip(AMateria* m)
{
    int i = -1;
    while (++i < 4)
    if (inventory[i] == NULL)
    {
        inventory[i] = m;
        return ;
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
        delete(&floor[floor_pin]);
    floor[floor_pin] = inventory[idx]->clone();
    delete(&inventory[idx]);
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
    inventory[idx]->use(target);
}