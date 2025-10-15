/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:13:07 by yoherfan          #+#    #+#             */
/*   Updated: 2025/09/29 14:31:22 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void ft_replace(std::string &result, std::string old_str, std::string new_str)
{	
	std::size_t	i = 0;

	i = result.find(old_str, i);
	while (i != std::string::npos)
	{
        result.erase(i, old_str.length());
        result.insert(i, new_str);
        i += new_str.length();
		i = result.find(old_str, i);
	}
}

int main(int argc, char **argv)
{
	std::ifstream	fs1;
	std::ofstream	fs2;
	std::string		filename;
	std::string		result;
	std::string		temp;
	char			c;
	
	temp = argv[2];
	if (argc != 4)
    	std::cout << "invalid number of arguments\n";
	else if (temp == "")
		std::cout << "searched string is empty\n";
	else
	{
		filename = (std::string)argv[1];
		fs1.open (filename.c_str());
		if (fs1.fail())
		{
			std::cout << "invalid input file\n";
			fs1.close();
		}
		else
		{
			while(fs1.get(c))
				result += c;
			ft_replace(result, argv[2], argv[3]);
			filename.append(".replace");
			fs2.open(filename.c_str());
			fs2 << result;
			fs1.close();
			fs2.close();
		}		
	}
}
