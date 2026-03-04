/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:35:51 by yoherfan          #+#    #+#             */
/*   Updated: 2026/01/12 13:11:48 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <math.h>

class Span
{
    private:

    unsigned int n_max;
    unsigned int index;
    std::vector<int> v;
    
    public:

    Span();
    Span(unsigned int size);
    Span(Span &a);
    ~Span();
    Span &operator = (Span const &value);

    void addNumber(int n);
    void addSequence(int range, int startingNumber);
    void showVector();
    unsigned int shortestSpan();
    unsigned int longestSpan();
    
    class FullVectorException : public std::exception
	{
		public:
		
		virtual const char *what() const throw();
	};
};

#endif