/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:04:06 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/05 10:33:03 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a;
        Bureaucrat b("Biagio", 200);
        Bureaucrat c("Ciruzzo", 0);
        // std::cout << "try\n";
        // a.dec_grade();
        // Bureaucrat d("Daniele", 100);
        // std::cout << d;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what();
    }
}
