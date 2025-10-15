/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:26:19 by yoherfan          #+#    #+#             */
/*   Updated: 2025/09/18 15:06:09 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int     i, n;
    Zombie* z;
    
    n = 5;
    i = -1;
    z = zombieHorde(n, "lucrezia");
    while (++i < n)
        z[i].announce();
    delete[] z;
}

