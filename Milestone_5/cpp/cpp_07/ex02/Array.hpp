/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:19:39 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/19 15:18:25 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>


template <typename T> class Array
{
	private:

	T *v;
	unsigned int size;
	
    public:
    
    Array();
    Array(unsigned int n);
    Array(Array &a);
    ~Array();

	Array &operator = (Array const &value);
	T &operator [] (unsigned int i);
    
    unsigned int Size();

	class OutOfBoundsException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#include "Array.tpp" 
#endif