/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:11:51 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/22 13:00:53 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public virtual ScavTrap, public virtual FragTrap
{
	private:
	
	std::string	clapName;

	public:
	
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap &trap);
	~DiamondTrap();

	DiamondTrap &operator=(DiamondTrap const &value);

	void attack(const std::string &target);
	void whoIam();
};

#endif