/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Http.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:15:12 by yoherfan          #+#    #+#             */
/*   Updated: 2026/04/09 18:22:04 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Http.hpp"


void HttpRequest::print_request()
{
    std::cout << "Method: " << this->method << std::endl
              << "Uri: " << this->uri << std::endl
              << "Version: " << this->version << std::endl
              << "\n# HEADERS #\n\n";
    std::map<std::string, std::string>::iterator it = this->headers.begin();
    std::map<std::string, std::string>::iterator ite = this->headers.end();
    while(it != ite)
    {
        std::cout << it->first << ": " << it->second << std::endl;
        it++;
    }          
}

bool HttpRequest::contains_body()
{
    std::map<std::string, std::string>::iterator it = headers.begin();
    std::map<std::string, std::string>::iterator ite = headers.end();

    while (it != ite)
    {
        if (it->first == /*CONTENT LENGHT*/)
    }
}


