/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:37:41 by yoherfan          #+#    #+#             */
/*   Updated: 2025/09/23 11:23:52 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
	public:
	Weapon		&w;
	std::string	name;
	void		attack();
				HumanA(std::string name, Weapon &weapon);
};