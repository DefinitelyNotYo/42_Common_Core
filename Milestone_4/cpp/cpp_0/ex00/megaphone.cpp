/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:51:06 by yoherfan          #+#    #+#             */
/*   Updated: 2025/09/25 18:38:42 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	int	i, j;
	std::string str;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		i = 0;
		while (++i < argc)
		{
			str = (std::string)argv[i];
			j = -1;
			while (++j < (int)str.length())
				std::cout << (char)std::toupper(str[j]);
		}
		std::cout << "\n";
	}
}
