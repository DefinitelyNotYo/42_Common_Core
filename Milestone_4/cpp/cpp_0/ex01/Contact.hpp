/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:35:02 by yoherfan          #+#    #+#             */
/*   Updated: 2025/09/25 18:08:51 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Contact
{
	private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone;
	std::string secret;
	public:
	void		add_first_name(std::string);
	void		add_last_name(std::string);
	void		add_nickname(std::string);
	void		add_phone(std::string);
	void		add_secret(std::string);
	std::string	get_first_name();
	std::string	get_last_name();
	std::string	get_nickname();
	std::string	get_phone();
	std::string	get_secret();
};
