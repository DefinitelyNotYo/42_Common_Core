/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:35:00 by yoherfan          #+#    #+#             */
/*   Updated: 2025/09/25 18:15:13 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::add_first_name(std::string str)
{
	first_name = str;
}

void	Contact::add_last_name(std::string str)
{
	last_name = str;
}

void	Contact::add_nickname(std::string str)
{
	nickname = str;
}

void	Contact::add_phone(std::string str)
{
	phone = str;
}

void	Contact::add_secret(std::string str)
{
	secret = str;
}

std::string	Contact::get_first_name()
{
	return (this->first_name);
}

std::string	Contact::get_last_name()
{
	return (this->last_name);
}

std::string	Contact::get_nickname()
{
	return (this->nickname);
}

std::string	Contact::get_phone()
{
	return (this->phone);
}

std::string	Contact::get_secret()
{
	return (this->secret);
}
