/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:30:05 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/03 09:52:08 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{    
    protected:

    std::string name;
    AMateria    *inventory[4];
    int          floor_pin;
    AMateria    *floor[4];
    
	public:

    Character();
    Character(Character &c);
	~Character();
    Character &operator=(Character const &value);

    Character(std::string n);

	std::string const &getName() const;
    void getInventory() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif