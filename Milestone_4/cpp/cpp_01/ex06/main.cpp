/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:13:07 by yoherfan          #+#    #+#             */
/*   Updated: 2025/10/01 13:21:57 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	std::string temp;
	
	if (argc != 2)
		std::cout << "Invalid number of arguments\n";
	else
	{
		temp = argv[1];
		harl.complain(temp);		
	}
}
