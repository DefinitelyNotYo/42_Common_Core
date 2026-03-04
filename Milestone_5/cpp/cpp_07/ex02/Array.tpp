/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:49:23 by yoherfan          #+#    #+#             */
/*   Updated: 2025/12/19 15:56:01 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template<typename T> Array<T>::Array()
{
    std::cout << "default constructor called\n";
    v = NULL;
    size = 0;
}

template<typename T> Array<T>::Array(unsigned int n)
{
    std::cout << "sized constructor called\n";
    size = n;
    v = new T[size];
    unsigned int i = 0;
    while (i < size)
    {
        v[i] = 0;
        i++;
    }
}

template<typename T> Array<T>::Array(Array &a)
{
    std::cout << "copy constructor called\n";
    size = a.Size();
    v = new T[size];
    unsigned int i = 0;
    while (i < size)
    {
        v[i] = a[i];
        i++;       
    }
}

template<typename T> Array<T>::~Array()
{
    if (v)
        delete[](v);
}


template<typename T> Array<T> &Array<T>::operator = (Array const &value)
{
    if(this->v == value)
        return (value);
    delete[](this->v);
    v = new T[value.Size()];
    size = value.Size();
    int i = -1;
    while (++i < size)
        v[i] = value[i];
}

template<typename T> T &Array<T>::operator [](unsigned int i)
{
    if(i < this->Size())
        return (v[i]);
    else
        throw OutOfBoundsException();
}

template<typename T> unsigned int Array<T>::Size()
{
    return (size);        
}

template<typename T> const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Invalid index");
}

#endif