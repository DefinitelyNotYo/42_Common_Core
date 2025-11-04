/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:08:21 by yoherfan          #+#    #+#             */
/*   Updated: 2025/11/03 11:51:00 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

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
	ClapTrap(ClapTrap &trap);
	~ClapTrap();

	ClapTrap &operator=(ClapTrap const &value);
	
	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif