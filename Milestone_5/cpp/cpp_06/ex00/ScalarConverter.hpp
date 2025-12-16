/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:04:04 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/16 12:17:27 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

#include <string>
#include <iostream>
#include <ostream>
#include <cstdlib>
#include <cerrno>
#include <climits> 

class ScalarConverter
{
	private:

	ScalarConverter();
	ScalarConverter(ScalarConverter &c);
	ScalarConverter &operator = (ScalarConverter const &value);
	~ScalarConverter();

	public:
	
	void static convert(std::string str);
	void static convert_char(std::string str);
	void static convert_int(std::string str);
	void static convert_float(std::string str);
	void static convert_double(std::string str);
	std::string static getType(std::string str);
};

#endif