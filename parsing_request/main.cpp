/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:56:16 by yoherfan          #+#    #+#             */
/*   Updated: 2026/04/09 18:22:35 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//RIPRENDI DA HTTP.CPP -> CONTROLLO SU CONTENT LENGHT PER VEDERE SE C'E' UN BODY


#include "External.hpp"
#include "Client.hpp"

int main()
{
	std::string		buffer;
    std::fstream	file;
    std::string		name = "req.txt";

	Client			utonto;

	
    file.open((name).c_str(), std::ios::in);
    if (!file)
		return (std::cerr << "Error: File not found\n", 0);
	while (getline(file, buffer))
		utonto.read_buf.append(buffer + "\r\n");

	utonto.parse_request();
}
