/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:04:06 by yoherfan          #+#    #+#             */
/*   Updated: 2026/01/12 13:17:11 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <string>

int main()
{
    Span w(30);
    
    try
    {
        w.addNumber(30);
        w.addNumber(38);
        w.addNumber(2);
        w.addNumber(96);
        w.addNumber(112);
        w.addNumber(7);    
        // w.addSequence(7, 11);   
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what();  
    }   
    w.showVector();
    std::cout << "\nlongest span is: " << w.longestSpan() 
              << std::endl;  
    std::cout << "\nshortest span is: " << w.shortestSpan() 
              << std::endl << std::endl;  
}
