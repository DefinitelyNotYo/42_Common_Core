/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:37:37 by yoherfan          #+#    #+#             */
/*   Updated: 2025/09/23 11:24:01 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
	public:
	Weapon		*w;
	std::string	name;
	void		attack();
	void		setWeapon(Weapon &weapon);
				HumanB(std::string name);
};