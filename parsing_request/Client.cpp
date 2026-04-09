/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:21:53 by yoherfan          #+#    #+#             */
/*   Updated: 2026/04/09 18:14:36 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

void Client::parse_request()
{
    parse_headers(); //gli header 
    // requests.push_back(ghost_request);
    // ghost_request.print_request();
}


void Client::parse_headers()
{
    int toggle = 3;
    int headers_end = read_buf.find("\r\n\r\n") + 2;
	int next_endl = read_buf.find("\r\n");
    int start = 0;
	
	for (int i = 0; i < headers_end; i++)
	{
		if (read_buf[i] == ' ')
		{
			if (toggle == 3)
			{
				ghost_request.method = read_buf.substr(start, i - start);
				start = i + 1;
				toggle--;
			}
			else if (toggle == 2)
			{
				ghost_request.uri = read_buf.substr(start, i - start);
				start = i + 1;
				toggle--;
			}
		}
		if (read_buf[i] == ':' && toggle == 0)
		{
			ghost_request.headers[read_buf.substr(0, i)] = \
			read_buf.substr(i + 2, next_endl - i - 1);
			i = next_endl;
		}
		if (i == next_endl)
		{
			if (toggle == 1)
			{
				ghost_request.version = read_buf.substr(start, i - start);
				toggle--;
			}
			headers_end -= i + 4;
			std::string sub_req = read_buf.substr(0, next_endl + 2);
			// std::cout << sub_req;
			read_buf = read_buf.substr(i + 2, read_buf.size() - i + 2);
			next_endl = read_buf.find("\r\n");
			i = 0;
			start = 0;
		}
	}
}
