/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 08:50:56 by yoherfan          #+#    #+#             */
/*   Updated: 2025/09/25 10:51:51 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
    int i;
    void (Harl::*complains[4])(void) = {&Harl::debug, &Harl::error, &Harl::info, &Harl::warning};
    std::string levels[4] = {"DEBUG", "ERROR", "INFO", "WARNING"};

    i = -1;
    while (++i < 4)
        if (level == levels[i])
        {
            (this->*complains[i])();
            break;
        }
}

void Harl::debug()
{
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::error()
{
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now.\n"; 
}

void Harl::info()
{
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn't put"
              << "enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Harl::warning()
{
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I've been coming for "
              << "years, whereas you started working here just last month\n";
}