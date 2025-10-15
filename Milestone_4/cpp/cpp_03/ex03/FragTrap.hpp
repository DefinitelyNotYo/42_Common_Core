/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:08:21 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/15 10:08:16 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{    
    public:
	
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();

	void	highFivesGuys();
	void	attack(const std::string &target);
};