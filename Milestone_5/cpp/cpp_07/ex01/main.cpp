/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:04:06 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/17 17:10:28 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Template.hpp"
#include <iostream>
#include <string>

void print_int(int &n)
{  
    std::cout << n << std::endl;
}

void print_char(char c)
{
    std::cout << c;
}

int main()
{
    int array[3] = {1, 2, 3};
    std::string s = "ciao\n";
    ::iter(array, 3, &print_int);
    ::iter(s, 5, &print_char);
    return 0;
}
