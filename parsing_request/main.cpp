/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:56:16 by yoherfan          #+#    #+#             */
/*   Updated: 2026/04/08 17:49:45 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Http.hpp"

int main()
{
	std::string		whole_request;
	std::string		buffer;
    std::fstream	file;
    std::string		name = "req.txt";

	// Http			request;
	// int				toggle = 2;
	
    file.open((name).c_str(), std::ios::in);
    if (!file)
		return (std::cerr << "Error: File not found\n", 0);
	while (getline(file, buffer))
		whole_request.append(buffer + "\r\n");
	int headers_end = whole_request.find("\r\n\r\n");
	std::cout << whole_request;
	std::cout << std::endl << whole_request.find("\r\n") << std::endl;
	for (int i = 0; i < headers_end; i = whole_request.find("\r\n") + 4)
	{
		int start = i;
	}
	

	
}