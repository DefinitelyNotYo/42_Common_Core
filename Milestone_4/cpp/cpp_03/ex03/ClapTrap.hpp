/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:08:21 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/14 14:40:11 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class ClapTrap
{
    private:
    std::string		name;
	int				hitPoints;
	int				energyPoints;
	int				attackDamage;
    
    public:
	
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();

	void		attack(const std::string &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	std::string get_name();
	int 		get_hitPoints();
	int 		get_energyPoints();
	int 		get_attackDamage();	
	void		set_name(std::string name);
	void		set_hitPoints(int hitPoints);
	void		set_energyPoints(int energyPoints);
	void		set_attackDamage(int attackDamage);
};