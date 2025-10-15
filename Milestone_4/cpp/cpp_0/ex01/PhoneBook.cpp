/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:35:07 by yoherfan          #+#    #+#             */
/*   Updated: 2025/09/09 12:26:27 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

void	PhoneBook::add_contact(PhoneBook *p)
{
    Contact 	c;
    std::string str;

    while (str == "")
    {
		std::cout << "First name: ";
		std::getline(std::cin, str);
		if (str != "") 
			c.add_first_name(str);
		else
			std::cout << "A contact can't have empty fields\n";
    }
    str = "";
	while (str == "")
    {
		std::cout << "Last name: ";
		std::getline(std::cin, str);
		if (str != "") 
			c.add_last_name(str);
		else
			std::cout << "A contact can't have empty fields\n";
    }
    str = "";
	while (str == "")
    {
		std::cout << "Nickname: ";
		std::getline(std::cin, str);
		if (str != "") 
			c.add_nickname(str);
		else
			std::cout << "A contact can't have empty fields\n";
    }
    str = "";
	while (str == "")
    {
		std::cout << "Phone: ";
		std::getline(std::cin, str);
		if (str != "") 
			c.add_phone(str);
		else
			std::cout << "A contact can't have empty fields\n";
    }
    str = "";
	while (str == "")
    {
		std::cout << "Secret: ";
		std::getline(std::cin, str);
		if (str != "") 
			c.add_secret(str);
		else
			std::cout << "A contact can't have empty fields\n";
    }
	p->phone_book[p->id] = c;
	p->id++;
	if (p->id > 7)
		p->id = 0;
}
