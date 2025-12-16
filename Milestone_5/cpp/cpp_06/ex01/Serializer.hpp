/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:04:04 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/16 16:28:16 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <ostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:

	Serializer();
	Serializer(Serializer &c);
	Serializer &operator = (Serializer const &value);
	~Serializer();

	public:
	
	uintptr_t static serialize(Data* ptr);
	Data static *deserialize(uintptr_t raw);

};

#endif