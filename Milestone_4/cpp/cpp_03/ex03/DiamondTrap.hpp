/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:11:51 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/15 10:11:32 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.cpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
	
	std::string	name;
	std::string	clapName;
	
	public:
	
};