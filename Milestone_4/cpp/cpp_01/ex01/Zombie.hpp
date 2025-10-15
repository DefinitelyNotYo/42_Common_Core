/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:28 by yoherfan          #+#    #+#             */
/*   Updated: 2025/09/18 14:54:08 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Zombie
{
    private:
    std::string name;
    
    public:
    
    void	announce();
	void    set_name(std::string name);
	~Zombie(void);
};

Zombie* zombieHorde(int N, std::string name);