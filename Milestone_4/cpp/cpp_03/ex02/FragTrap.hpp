/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:08:21 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/14 14:56:45 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{    
    public:
	
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();

	void	highFivesGuys();
	void	attack(const std::string &target);
};