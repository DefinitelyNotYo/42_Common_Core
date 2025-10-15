/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:19 by yoherfan          #+#    #+#             */
/*   Updated: 2025/09/18 14:16:00 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* z;
    
    randomChump("Zombie 1");
    z = newZombie("Zombie 2");
    z->announce();
    delete(z);
}

