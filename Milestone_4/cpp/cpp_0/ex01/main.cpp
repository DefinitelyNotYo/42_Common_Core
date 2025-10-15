/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:35:04 by yoherfan          #+#    #+#             */
/*   Updated: 2025/09/25 18:14:27 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <stdlib.h> 

void	display_phonebook(PhoneBook p, int i)
{
	int buffer;
	int	index;

	std::cout << "         " << i + 1 << "|";
	if (p.phone_book[i].get_first_name().length() < 9)
	{
		buffer = 11 - p.phone_book[i].get_first_name().length();
		while (--buffer != 0)
			std::cout << " ";
		std::cout << p.phone_book[i].get_first_name() << "|";
	}
	else
	{
		index = -1;
		while (++index < 9)
			std::cout << p.phone_book[i].get_first_name()[index];
		std::cout << ".|";
	}
	if (p.phone_book[i].get_last_name().length() < 9)
	{
		buffer = 11 - p.phone_book[i].get_last_name().length();
		while (--buffer != 0)
			std::cout << " ";
		std::cout << p.phone_book[i].get_last_name() << "|";
	}
	else
	{
		index = -1;
		while (++index < 9)
			std::cout << p.phone_book[i].get_last_name()[index];
		std::cout << ".|";
	}
	if (p.phone_book[i].get_nickname().length() < 9)
	{
		buffer = 11 - p.phone_book[i].get_nickname().length();
		while (--buffer != 0)
			std::cout << " ";
		std::cout << p.phone_book[i].get_nickname() << std::endl;
	}
	else
	{
		index = -1;
		while (++index < 9)
			std::cout << p.phone_book[i].get_nickname()[index];
		std::cout << "." << std::endl;
	}
}

void	display_show_contact(PhoneBook p, int i)
{
	if (p.phone_book[i].get_first_name() != "")
	{
		std::cout << "\nfirst name: " << p.phone_book[i].get_first_name() << std::endl;
		std::cout << "last name: " << p.phone_book[i].get_last_name() << std::endl;
		std::cout << "nickname: " << p.phone_book[i].get_nickname()<< std::endl;
		std::cout << "phone: " << p.phone_book[i].get_phone()<< std::endl;
		std::cout << "secret: " << p.phone_book[i].get_secret() << std::endl;		
	}
}

int	main()
{
	PhoneBook	rubrica;
	std::string prompt;
	int			i;

	rubrica.id = 0;
	while (prompt != "EXIT")
	{
		std::cout << "Welcome to your phonebook! The program only accepts ADD, SEARCH and EXIT\n> ";
		std::getline(std::cin, prompt);
		if (prompt == "ADD")
			rubrica.add_contact(&rubrica);
		else if (prompt == "SEARCH")
		{
			if (rubrica.phone_book[0].get_first_name() == "")
				std::cout << "\nPhonebook is empty.\n";
			else
			{
				std::cout << std::endl;
				i = 0;
				while (i < 8 && rubrica.phone_book[i].get_first_name() != "")
				{
					display_phonebook(rubrica, i);
					i++;
				}
				while (prompt != "BACK")
				{
					std::cout << "\nInsert a valid id number or BACK to go to menu'\n> ";
					std::getline(std::cin, prompt);
					if (std::atoi(prompt.c_str()) > 0 && std::atoi(prompt.c_str()) < 8)
						display_show_contact(rubrica, std::atoi(prompt.c_str()) - 1);						
				}				
			}
		}
		std::cout << std::endl;
	}
}