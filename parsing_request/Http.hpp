/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Http.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:15:18 by yoherfan          #+#    #+#             */
/*   Updated: 2026/04/08 17:12:27 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTP_HPP
# define HTTP_HPP

# include <iostream>
# include <vector>
# include <ostream>
# include <unistd.h>
# include <fcntl.h>

#include <string>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <stdlib.h>

class Http
{
	public:

		std::map<std::string, std::string>	_headers;
		std::string method;
		std::string version;
		std::string uri;
		std::string body;

};

#endif
