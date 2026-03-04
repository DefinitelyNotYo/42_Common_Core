/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:35:53 by yoherfan          #+#    #+#             */
/*   Updated: 2026/01/12 13:14:38 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
    n_max = 0;
    index = 0;
}
Span::Span(unsigned int size)
{
    n_max = size;
    index = 0;
}

Span::Span(Span &a)
{
    *this = a;
}
Span::~Span()
{
    // v.clear();
}
Span &Span::operator = (Span const &value)
{
    if (this == &value)
		return (*this);
	n_max = value.n_max;
    index = value.index;
    unsigned int i = 0;
    while (i < n_max)
    {
        addNumber(value.v[i]);
        i++;
    }
	return (*this);
}

void Span::addNumber(int n)
{
    if (index + 1 > n_max)
        throw FullVectorException();
    index++;
    v.push_back(n);
}

void Span::addSequence(int range, int startingNumber)
{
    int i = -1;
    while (++i < range)
    {
        addNumber(startingNumber);
        startingNumber++;
    }
}

void Span::showVector()
{
    int i = 0;
    while (v.begin() + i != v.end())
    {
        std::cout << v.at(i) << std::endl;
        i++;
    }
}

unsigned int Span::shortestSpan()
{
    int distance = (int)longestSpan();
    
    unsigned int i = 0;
    while (i < index)
    {
        unsigned int j = i + 1;
        while (j < index)
        {
            if (abs(v[i] - v[j]) < distance)
                distance = abs(v[i] - v[j]);
            j++;
        }
        i++;
    }
    return (distance);
}

unsigned int Span::longestSpan()
{
    int max;
    int min;
    
    max = *v.begin();
    min = *v.begin();

    int i = 0;
    while (v.begin() + i != v.end())
    {
        if (v.at(i) > max)
            max = v.at(i);
        if (v.at(i) < min)
            min = v.at(i);
        i++;
    }
    return (max - min);
}

const char *Span::FullVectorException::what() const throw()
{
	return ("Max capacity reached\n");
}