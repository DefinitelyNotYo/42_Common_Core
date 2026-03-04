/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:04:06 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/19 15:58:35 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>
#include <iostream>
#include <ostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <stdint.h>

int main()
{
    try
    {
        Array<int> a(5);
        a[1] = 1;
        unsigned int i = 0;
        while (i < a.Size())
        {
            std::cout << a[i] << std::endl;
            i++;       
        }
        
        Array<int> b(10);
        b[8] = a[1];
        i = 0;
        while (i < b.Size())
        {
            std::cout << b[i] << std::endl;
            i++;       
        }

        Array<int> c(b);
        i = 0;
        while (i < c.Size())
        {
            std::cout << c[i] << std::endl;
            i++;       
        }
        
        Array<int> d = c;
        i = 0;
        while (i < d.Size())
        {
            std::cout << d[i] << std::endl;
            i++;       
        }        
        std::cout << a[20] << std::endl;
    }
	catch (std::exception &e)
    {
		std::cout << e.what() << std::endl;        
    }
}
