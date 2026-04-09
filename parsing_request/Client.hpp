/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:21:56 by yoherfan          #+#    #+#             */
/*   Updated: 2026/04/09 17:48:30 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "External.hpp"
# include "Http.hpp"

class Client
{
	public:

        std::string			        read_buf;
		std::vector<HttpRequest>	requests;
        HttpRequest                 ghost_request;
        
        void parse_request();
        void parse_headers();

};

#endif