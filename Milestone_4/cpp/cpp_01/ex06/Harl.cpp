/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 08:50:56 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/01 13:20:26 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
    int i;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    i = -1;
    while (++i < 4)
        if (level == levels[i])
            break;
    switch(i)
    {
        case 0:
        {
            this->debug();
            std::cout << std::endl;       
        }
        case 1:
        {
            this->info();
            std::cout << std::endl;          
        }
        case 2:
        {
            this->warning();
            std::cout << std::endl;           
        }
        case 3:
        {
            this->error();
            std::cout << std::endl;
            break;            
        }
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
            break;
    }
}

void Harl::debug()
{
    std::cout << "[ DEBUG ]\n I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::error()
{
    std::cout << "[ ERROR ]\n This is unacceptable! I want to speak to the manager now.\n"; 
}

void Harl::info()
{
    std::cout << "[ INFO ]\n I cannot believe adding extra bacon costs more money. You didn't put"
              << "enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Harl::warning()
{
    std::cout << "[ WARNING ]\n I think I deserve to have some extra bacon for free. I've been coming for "
              << "years, whereas you started working here just last month\n";
}